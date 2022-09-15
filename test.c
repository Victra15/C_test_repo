/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:57:57 by yolee             #+#    #+#             */
/*   Updated: 2022/09/16 03:59:29 by yolee            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int			errcode;
	struct stat	buf;

	(void)argc;
	(void)argv;
	errcode = stat(argv[1], &buf);
	printf("%d %d\n", errcode, S_ISDIR(buf.st_mode));
	return (0);
}
