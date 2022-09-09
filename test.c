/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:57:57 by yolee             #+#    #+#             */
/*   Updated: 2022/09/09 19:50:59 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define PIPE_OUT 0
#define PIPE_IN 1

int	main(int argc, char **argv)
{
	int		exit_status;
	int		file_fd;
	int		pipefd_A[2];
	int		pipefd_B[2];
	pid_t	c_pid;

	(void)argc;
	exit_status = 0;
	pipe(pipefd_A);
	pipe(pipefd_B);
	c_pid = fork();
	if (c_pid == 0)
	{
		file_fd = open("temp.txt", O_RDONLY);
		printf("%d, %d\n", pipefd_A[PIPE_IN], pipefd_A[PIPE_OUT]);
		close(pipefd_A[PIPE_OUT]);
		dup2(file_fd, STDIN_FILENO);
		dup2(pipefd_A[PIPE_IN], STDOUT_FILENO);
		execve("/bin/cat", argv, NULL);
		exit(EXIT_SUCCESS);
	}
	waitpid(c_pid, &exit_status, WUNTRACED);
	c_pid = fork();
	if (c_pid == 0)
	{
		printf("%d, %d\n", pipefd_B[PIPE_IN], pipefd_B[PIPE_OUT]);
		close(pipefd_A[PIPE_IN]);
		dup2(pipefd_A[PIPE_OUT], STDIN_FILENO);
		execve("/bin/cat", argv, NULL);
		exit(EXIT_SUCCESS);
	}
	execve("/bin/cat", argv, NULL);
	return (0);
}

// int	g_num;

// int	main()
// {
// 	int		exit_status;
// 	pid_t	c_pid;

// 	g_num = 0;
// 	exit_status = 0;
// 	c_pid = fork();
// 	if (c_pid == 0)
// 	{
// 		g_num = 5;
// 		printf("%d\n", g_num);
// 		exit(EXIT_SUCCESS);
// 	}
// 	g_num = 1;
// 	waitpid(c_pid, &exit_status, WUNTRACED);
// 	c_pid = fork();
// 	if (c_pid == 0)
// 	{
// 		g_num = 10;
// 		printf("%d\n", g_num);
// 		exit(EXIT_SUCCESS);
// 	}
// 	waitpid(c_pid, &exit_status, WUNTRACED);
// 	printf("%d\n", g_num);
// 	return (0);
// }

// int	main()
// {
// 	int fd;

// 	fd = open("a.txt", O_RDWR);
// 	printf("%d\n", fd);
// }
