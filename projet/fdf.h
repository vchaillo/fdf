/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:24:48 by vchaillo          #+#    #+#             */
/*   Updated: 2014/12/15 21:41:17 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libft/includes/libft.h"

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	char		*path;
}				t_env;

int		start_mlx(char *path);
void	create_map(t_env *e);
int		get_tab_len(t_env *e);
int		*get_int_tab(char *line);

# define WIN_H 720
# define WIN_W 1280

#endif
