#include <unistd.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const av[], char type)
{
   int fd[2];
   pid_t pid;

   if (!file || !av || (type != 'r')&& (type != 'w') || pipe(fd) == -1)
    return (-1);
    

}