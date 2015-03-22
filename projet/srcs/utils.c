/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:31:06 by vchaillo          #+#    #+#             */
/*   Updated: 2015/03/22 08:56:27 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				get_grid_len(t_env *e)
{
	char		*buffer;
	int			fd;
	int			len;
	int			ret;

	len = 0;
	buffer = ft_strnew(BUFF_SIZE);
	if ((fd = open(e->path, O_RDONLY)) == -1)
	{
		close(fd);
		open_error(e);
	}
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		len += check_char(buffer);
	}
	close(fd);
	free(buffer);
	return (len);
}

int				check_char(char *str)
{
	int			i;
	int			val;
	int			len;

	i = 0;
	val = 1;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\n')
			val = 1;
		if (str[i] != ' ' && str[i] != '\n' && val == 1)
		{
			len++;
			val = 0;
		}
		i++;
	}
	return (len);
}

int				get_tab_len(char **tab)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = 2;
	while (tab[i][j])
	{
		ft_putendl("You find me!");
		j++;
		i++;
	}
	return (len);
}

/*
int				get_tab_len(char **tab)
{
	int			len;
	int			i;

	i = 0;
	len = 0;
	while (tab[len])
	{
		if (*tab[i] != '\n')
		{
			len++;
			ft_putendl("You find me!");
		}
		i++;
	}
	return (len);
}*/
