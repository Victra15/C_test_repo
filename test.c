/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:57:57 by yolee             #+#    #+#             */
/*   Updated: 2022/09/10 11:35:54 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define PIPE_RD 0
#define PIPE_WR 1

int	main(int argc, char **argv)
{
	int		exit_status;
	int		file_fd;
	int		pipefd[2];
	int		pipefd_1[2];
	pid_t	c_pid;

	(void)argc;
	exit_status = 0;
	pipe(pipefd);
	c_pid = fork();
	if (c_pid == 0)
	{
		close(pipefd[PIPE_RD]);
		file_fd = open("temp.txt", O_RDONLY);
		dup2(file_fd, STDIN_FILENO);
		dup2(pipefd[PIPE_WR], STDOUT_FILENO);
		execve("/bin/cat", argv, NULL);
		exit(EXIT_SUCCESS);
	}
	waitpid(c_pid, &exit_status, WUNTRACED);
	pipe(pipefd_1);
	c_pid = fork();
	if (c_pid == 0)
	{
		close(pipefd[PIPE_WR]);
		close(pipefd_1[PIPE_RD]);
		dup2(pipefd[PIPE_RD], STDIN_FILENO);
		dup2(pipefd_1[PIPE_WR], STDOUT_FILENO);
		execve("/bin/cat", argv, NULL);
		exit(EXIT_SUCCESS);
	}
	else
		close(pipefd[PIPE_WR]);
	waitpid(c_pid, &exit_status, WUNTRACED);
	close(pipefd[PIPE_RD]);
	pipe(pipefd);
	c_pid = fork();
	if (c_pid == 0)
	{
		close(pipefd_1[PIPE_WR]);
		close(pipefd[PIPE_RD]);
		dup2(pipefd_1[PIPE_RD], STDIN_FILENO);
		dup2(pipefd[PIPE_WR], STDOUT_FILENO);
		execve("/bin/cat", argv, NULL);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipefd_1[PIPE_WR]);
	}
	waitpid(c_pid, &exit_status, WUNTRACED);
	pipe(pipefd_1);
	c_pid = fork();
	if (c_pid == 0)
	{
		close(pipefd[PIPE_WR]);
		dup2(pipefd[PIPE_RD], STDIN_FILENO);
		execve("/bin/cat", argv, NULL);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipefd[PIPE_WR]);
	}
	waitpid(c_pid, &exit_status, WUNTRACED);
	return (0);
}
