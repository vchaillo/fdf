/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 02:52:24 by valentin          #+#    #+#             */
/*   Updated: 2017/04/03 08:45:14 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	open_error(t_env *e)
{
	ft_putstr("Failed to open ");
	ft_putstr(e->path);
	ft_putendl(" file");
	exit(0);
}

void	malloc_error(void)
{
	ft_putendl("Memory allocation error");
	exit(0);
}

void	argument_error(char *arg)
{
	ft_putstr("Unknow option : ");
	ft_putendl(arg);
	exit(0);
}
