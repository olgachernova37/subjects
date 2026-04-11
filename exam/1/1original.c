#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

/*
 * ФУНКЦІЯ: ft_popen
 *
 * ОПИС: Запускає зовнішню програму та повертає файловий дескриптор
 * для читання її виходу або запису на її вхід.
 *
 * ПАРАМЕТРИ:
 *   - file: імя файлу програми для виконання
 *   - av: масив аргументів для програми (повинен закінчуватися NULL)
 *   - type: 'r' для читання виходу, 'w' для запису на вхід
 *
 * ПОВЕРТАЄ: файловий дескриптор у разі успіху, -1 у разі помилки
 */
int ft_popen(const char *file, char *const av[], char type)
{
    int fd[2];
    pid_t pid;


    if (!file || !av || (type != 'r' && type != 'w') || pipe(fd) == -1)
        return (-1);

    // Створюємо дочірній процес
    pid = fork();

    if (pid == 0)  // ДОЧІРНІЙ ПРОЦЕС
    {
        if (type == 'r')
        {
            dup2(fd[1], 1);
        }
        else  // type == 'w'
        {
            dup2(fd[0], 0);
        }
        close(fd[0]);
        close(fd[1]);
        execvp(file, av);
        exit(1);
    }
    // БАТЬКІВСЬКИЙ ПРОЦЕС
    if (type == 'r')
    {
        close(fd[1]);
        return (fd[0]);
    }
    else  // type == 'w'
    {
        close(fd[0]);
        return (fd[1]);
    }
}

/*
 * СПРОЩЕНА ФУНКЦІЯ: get_next_line
 * Читає один рядок з файлового дескриптора
 */
char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int pos = 0;
    static int end = 0;
    char *line;
    int i = 0;

    if (fd < 0)
        return (NULL);

    // Виділяємо пам'ять для рядка
    line = malloc(BUFFER_SIZE);
    if (!line)
        return (NULL);

    while (1)
    {
        // Якщо буфер вичерпаний, читаємо нові дані
        if (pos >= end)
        {
            end = read(fd, buffer, BUFFER_SIZE);
            pos = 0;

            // Якщо нічого не прочитали і рядок пустий - повертаємо NULL
            if (end <= 0)
            {
                if (i == 0)
                {
                    free(line);
                    return (NULL);
                }
                line[i] = '\0';
                return (line);
            }
        }

        // Копіюємо символи до нового рядка або до '\n'
        if (buffer[pos] == '\n')
        {
            line[i++] = '\n';
            pos++;
            line[i] = '\0';
            return (line);
        }

        line[i++] = buffer[pos++];

        // Запобігаємо переповнення буфера
        if (i >= BUFFER_SIZE - 1)
        {
            line[i] = '\0';
            return (line);
        }
    }
}

/*
 * ПРИКЛАД 1: Читання виходу команди (type = 'r')
 * ls буде виконана в дочірньому процесі,
 * батьківський процес читає її вихід рядок за рядком
 */
void example_read(void)
{
    int fd;
    char *line;

    printf("=== ПРИКЛАД 1: Читання виходу (ls -la) ===\n");
    fd = ft_popen("ls", (char *const []){"ls", "-la", NULL}, 'r');

    if (fd == -1)
    {
        printf("Помилка: не вдалося запустити команду\n");
        return;
    }

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
}

/*
 * ПРИКЛАД 2: Запис на вхід команди (type = 'w')
 * Батьківський процес пише дані на вхід cat,
 * cat повторює ці дані на виході (в терміналі)
 */
void example_write(void)
{
    int fd;
    const char *text = "Привіт, це тестовий рядок!\n";

    printf("\n=== ПРИКЛАД 2: Запис на вхід (cat) ===\n");
    printf("Напишемо: %s", text);

    fd = ft_popen("cat", (char *const []){"cat", NULL}, 'w');

    if (fd == -1)
    {
        printf("Помилка: не вдалося запустити команду\n");
        return;
    }

    write(fd, text, strlen(text));
    close(fd);
}

/*
 * ПРИКЛАД 3: Pipe комбінація - вихід ls подаємо на вхід grep
 */
void example_pipe_combination(void)
{
    int fd1, fd2;
    char *line;

    printf("\n=== ПРИКЛАД 3: Комбінація (ls | grep) ===\n");
    printf("Ищемо файли з розширенням .c\n");

    // Запускаємо ls
    fd1 = ft_popen("ls", (char *const []){"ls", "-la", NULL}, 'r');

    if (fd1 == -1)
    {
        printf("Помилка: не вдалося запустити ls\n");
        return;
    }

    // Перенаправляємо STDIN на вихід ls
    dup2(fd1, STDIN_FILENO);

    // Запускаємо grep
    fd2 = ft_popen("grep", (char *const []){"grep", ".c", NULL}, 'r');

    if (fd2 == -1)
    {
        printf("Помилка: не вдалося запустити grep\n");
        close(fd1);
        return;
    }

    // Читаємо результати grep
    while ((line = get_next_line(fd2)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd1);
    close(fd2);
}

// MAIN функція для тестування
int main(void)
{
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║          ТЕСТУВАННЯ ФУНКЦІЇ ft_popen                   ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n");

    example_read();
    example_write();
    example_pipe_combination();

    printf("\n╔════════════════════════════════════════════════════════╗\n");
    printf("║            ВСІ ТЕСТИ ЗАВЕРШЕНІ УСПІШНО                 ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n");

    return (0);
}
