/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:14:51 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/30 11:42:43 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//check the if .ber extension is met
void	ft_check_extension(char *argv, t_mlx *mlx)
{
	int	end;

	end = ft_strlen(argv) - 1;
	if (argv[end] == 'r' && argv[end - 1] == 'e'
		&& argv[end - 2] == 'b' && argv[end - 3] == '.')
		return ;
	else
		ft_errmsgs(mlx, 5);
}

//checks that the map has only the allowed characters
void	ft_check_pec10(t_mlx *mlx)
{
	int		i;

	i = 0;
	while (mlx->map.line[i])
	{
		if (mlx->map.line[i] != 'P' && mlx->map.line[i] != 'E'
			&& mlx->map.line[i] != 'C' && mlx->map.line[i] != '1'
			&& mlx->map.line[i] != '0' && mlx->map.line[i] != 'X')
			ft_errmsgs(mlx, 3);
		i++;
	}
}

//checks if there is at least one of each (player,collectible,exit)
void	ft_check_pec(t_mlx *mlx)
{
	int	i;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	mlx->map.collect = 0;
	while (mlx->map.line[i])
	{
		if (mlx->map.line[i] == 'P')
		{
			p++;
			mlx->map.player = i;
		}
		if (mlx->map.line[i] == 'E')
			e++;
		if (mlx->map.line[i] == 'C')
			mlx->map.collect++;
		i++;
	}
	if (p != 1 || e == 0 || mlx->map.collect == 0)
		ft_errmsgs(mlx, 1);
	ft_check_pec10(mlx);
}

//check the size and if the wall is composed by 1s
void	ft_check_sizenwall(t_mlx *mlx)
{
	size_t	i;

	i = 0;
	if (mlx->map.map_height * mlx->map.map_width != ft_strlen(mlx->map.line))
		ft_errmsgs(mlx, 2);
	while (i++ < mlx->map.map_width)
		if (mlx->map.line[i] != '1')
			ft_errmsgs(mlx, 2);
	i = ft_strlen(mlx->map.line) - mlx->map.map_width - 1;
	while (i++ < ft_strlen(mlx->map.line) - 1)
		if (mlx->map.line[i] != '1')
			ft_errmsgs(mlx, 2);
	i = mlx->map.map_width;
	while (i < ft_strlen(mlx->map.line) - mlx->map.map_width - 1)
	{
		if (mlx->map.line[i] == '1')
			i += mlx->map.map_width - 1;
		else
			ft_errmsgs(mlx, 2);
		if (mlx->map.line[i] == '1')
			i += 1;
		else
			ft_errmsgs(mlx, 2);
	}
	ft_check_pec(mlx);
}

//tranform the file in a char array
void	ft_get_map(t_mlx *mlx, char *argv)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_errmsgs(mlx, 4);
	line = get_next_line(fd);
	if (!line)
		ft_errmsgs(mlx, 4);
	mlx->map.map_width = ft_strlen(line) - 1;
	mlx->map.line = ft_strdup_nonl(line);
	free(line);
	while (line != NULL)
	{
		mlx->map.map_height += 1;
		line = get_next_line(fd);
		if (line)
		{	
			mlx->map.line = ft_strjoin(mlx->map.line, line);
			free(line);
		}
	}
	close(fd);
	ft_check_extension(argv, mlx);
	ft_check_sizenwall(mlx);
}
