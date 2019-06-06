/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:05:26 by abarthel          #+#    #+#             */
/*   Updated: 2019/06/06 14:50:45 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <errno.h>
#include "error.h"
#include "parser.h"
#include "libft.h"

static int	print_file_info(char *prog_name, char *path,
		t_options *options, struct stat *statbuf)
{
	(void)prog_name;
	ft_printf("%s\n", path);
	(void)options;
	(void)statbuf;
	return (OK);
}

int			file_info(char *prog_name, char *path, t_options *options)
{
	struct stat	statbuf;
	int			ret_value;

	ret_value = 0;
	if (stat(path, &statbuf))
		return (print_error(prog_name, path));
	else
	{
		ret_value = print_file_info(prog_name, path, options, &statbuf);
		return (ret_value);
	}
}
