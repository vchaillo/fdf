/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 02:52:24 by valentin          #+#    #+#             */
/*   Updated: 2014/12/17 03:01:55 by valentin         ###   ########.fr       */
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
