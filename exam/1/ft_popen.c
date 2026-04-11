#include <unistd.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const av[], char type)
{
int fd[2];
pid_t pid;

if(!file || !av || (type != 'r' && type != 'w') || pipe(fd) == -1)
    return (-1);

    pid = fork();
    if (pid == 0)
    {
        if (type == 'r')
            dup2(fd[1],1);
        else
            dup2(fd[0],0);
        close(fd[0]);
        close(fd[1]);
        execvp(file,av);
        exit(1);
    }
    
}
