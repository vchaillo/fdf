/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 23:35:21 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/13 16:14:46 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		load_window(void);

int		main(int ac, char **av)
{
	if (ac == 2)
		mlx_start(av[1]);
	else
		printf("FUCK YOU, I WON'T START MUHAHAHAHAHAHA\n");
	return (0);
}
