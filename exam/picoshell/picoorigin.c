#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int	picoshell(char **cmds[])
{
	int		i;
	int		fd[2];
	int		in_fd;
	pid_t	pid;

	i = 0;
	in_fd = 0;
	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd) == -1)
			return (1);
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			if (in_fd != 0)
			{
				dup2(in_fd, 0);
				close(in_fd);
			}
			if (cmds[i + 1])
			{
				close(fd[0]);
				dup2(fd[1], 1);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		else
		{
			if (in_fd != 0)
				close(in_fd);
			if (cmds[i + 1])
			{
				close(fd[1]);
				in_fd = fd[0];
			}
		}
		i++;
	}
	while (wait(NULL) > 0)
		;
	return (0);
}
