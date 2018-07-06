#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>

int	main(int ac, char **av) {
  int	pipefd[2];
  int	infd;
  int	outfd;
  pid_t	pid;

  if (ac < 2
      || (infd = open(av[1], O_RDONLY)) == -1
      || (outfd = creat(av[4], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1
      || dup2(infd, 0) == -1
      || pipe(pipefd) == -1
      || (pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      if (close(pipefd[0]) == -1
	  || dup2(pipefd[1], 1) == -1
	  || execlp("/bin/sh", "/bin/sh", "-c", av[2], NULL) == -1)
	return (1);
    }
  else
    {
      if (close(pipefd[1]) == -1
	  || dup2(pipefd[0], 0) == -1
	  || dup2(outfd, 1) == -1
	  || execlp("/bin/sh", "/bin/sh", "-c", av[3], NULL) == -1)
	return (1);
    }
  return (0);
}
