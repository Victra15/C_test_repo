/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:57:57 by yolee             #+#    #+#             */
/*   Updated: 2022/09/16 07:57:01 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define PIPE_RD 0
#define PIPE_WR 1

int	main(void)
{
	int	fd;

	fd = open("temp.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	printf("%d\n", fd);
	close(fd);
	return (0);
}


// void	ms_execute_cmd(t_cmd *cmd)
// {
// 	pid_t	c_pid;

// 	if (cmd->next)
// 		ms_init_pipe(cmd->index);
// 	c_pid = fork();
// 	if (c_pid == 0)
// 		ms_child_proc_act(cmd);
// 	else
// 		ms_close_pipe(cmd);
// 	waitpid(c_pid, &g_config.exit_status, WUNTRACED);
// }

// void	ms_init_pipe(int cmd_idx)
// {
// 	int	init_flag;

// 	init_flag = cmd_idx % 2;
// 	pipe(g_config.pipefd[init_flag]);
// }

// void	ms_close_pipe(t_cmd *cmd)
// {
// 	if (cmd->index % 2)
// 	{
// 		if (cmd->next)
// 			close(g_config.pipefd[0][FD_WR]);
// 		if (cmd->index != 0)
// 			close(g_config.pipefd[1][FD_RD]);
// 	}
// 	else
// 	{
// 		if (cmd->next)
// 			close(g_config.pipefd[1][FD_WR]);
// 		close(g_config.pipefd[0][FD_RD]);
// 	}
// }

// void	connect_pipe(t_cmd *cmd, int *in_fd, int *out_fd)
// {
// 	if (cmd->index % 2)
// 	{
// 		if (cmd->next)
// 			(*out_fd) = g_config.pipefd[0][FD_WR];
// 		if (cmd->index != 0)
// 			(*in_fd) = g_config.pipefd[1][FD_RD];
// 	}
// 	else
// 	{
// 		if (cmd->next)
// 			(*out_fd) = g_config.pipefd[1][FD_WR];
// 		(*in_fd) = g_config.pipefd[0][FD_RD];
// 	}
// }

// int		heredoc


// int		ms_open_infile(t_file *file)
// {

// }

// int		ms_open_outfile(t_file *file)
// {
// 	int			fd;
// 	struct stat	buf;

// 	while (1)
// 	{
// 		if (file->mode == APPEND_MODE)
// 			fd = open(fd, O_CREAT | O_WRONLY | O_APPEND, 0644);
// 		else
// 			fd = open(fd, O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 		if (!file && file->next)
// 			break ;
// 		close(fd);
// 	}
// }


// void	ms_child_proc_act(t_cmd *cmd)
// {
// 	int	in_fd;
// 	int	out_fd;

// 	in_fd = 0;
// 	out_fd = 0;
// 	connect_pipe(&in_fd, &out_fd);
// 	if (cmd->infile)
// 		in_fd = ms_open_infile(cmd->infile);
// 	if (cmd->outfile)
// 		out_fd = ms_open_outfile(cmd->outfile);
// 	dup2(out_fd, STDOUT_FILENO);
// 	dup2(in_fd, STDIN_FILENO);
// 	ms_execute(cmd->cmd);
// 	exit(EXIT_SUCCESS);
// }