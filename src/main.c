/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:22:44 by vchaillo          #+#    #+#             */
/*   Updated: 2015/03/19 23:38:29 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
		start_mlx(argv[1]);
	else
		ft_putendl("Insert a map here please!");
	return (0);
}
