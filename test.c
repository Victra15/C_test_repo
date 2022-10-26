/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:57:57 by yolee             #+#    #+#             */
/*   Updated: 2022/10/26 22:18:21 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#define PIPE_RD 0
#define PIPE_WR 1

static int	ft_isspace(const char chr)
{
	if ((chr >= '\t' && chr <= '\r')
		|| chr == ' ')
		return (1);
	else
		return (0);
}

static int	ft_issign(const char chr)
{
	if (chr == '+' || chr == '-')
		return (1);
	else
		return (0);
}

static int	ft_isoverflowed(double *conv_num, const int sign)
{
	if (((*conv_num) * (double)sign) < 0)
	{
		if (sign < 0)
			(*conv_num) = 0.0;
		else
			(*conv_num) = -1.0;
		return (1);
	}
	else
		return (0);
}

static double	getnum(const char **iter_ptr, int sign, int *cnt)
{
	double	conv_num;

	(*cnt) = 0;
	conv_num = 0.0;
	while (ft_isdigit(**iter_ptr))
	{
		conv_num = (conv_num * 10.0) + (double)((sign) * ((**iter_ptr) - '0'));
		if (ft_isoverflowed(&conv_num, sign))
			break ;
		(*iter_ptr)++;
		(*cnt)++;
	}
	return (conv_num);
}

double	ft_atof(const char *str)
{
	double		conv_num;
	int			sign;
	const char	*iter_ptr;
	int			cnt;

	sign = 1;
	conv_num = 0;
	iter_ptr = str;
	while (ft_isspace(*iter_ptr))
		iter_ptr++;
	if (ft_issign(*iter_ptr))
	{
		if ((*iter_ptr) == '-')
			sign = -1;
		iter_ptr++;
	}
	conv_num = getnum(&iter_ptr, sign, &cnt);
	if (*iter_ptr == '.' && ft_isdigit(*(iter_ptr + 1)) && iter_ptr++)
		conv_num += getnum(&iter_ptr, sign, &cnt) / pow(10.0, (double)cnt);
	else if (*iter_ptr != '\0')
		write(2, "error\n", 6);
	if (*iter_ptr != '\0')
		write(2, "error\n", 6);
	return ((conv_num));
}


int	main(int argc, char **argv)
{
	double	lf;
	(void)argc;
	lf = ft_atof(argv[1]);
	printf("%.15lf\n", lf);
	printf("%.15lf\n", 1.123123871827381728);
	return (0);
}
