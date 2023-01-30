/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:33:27 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/20 10:40:26 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_mv_w(t_mlx *mlx)
{
	if (mlx->map.line[mlx->map.player - mlx->map.map_width] == 'E'
		&& mlx->map.collect == 0)
	{	
		mlx->map.line[mlx->map.player] = '0';
		mlx->map.steps++;
		ft_game_msgs(mlx, 1);
	}
	if (mlx->map.line[mlx->map.player - mlx->map.map_width] == 'X')
		ft_game_msgs(mlx, 3);
	if (mlx->map.line[mlx->map.player - mlx->map.map_width] == '0'
		|| mlx->map.line[mlx->map.player - mlx->map.map_width] == 'C')
	{
		if (mlx->map.line[mlx->map.player - mlx->map.map_width] == 'C')
			mlx->map.collect--;
		mlx->map.steps++;
		mlx->map.line[mlx->map.player] = '0';
		mlx->map.line[mlx->map.player - mlx->map.map_width] = 'P';
		mlx->map.p_path = "srcs/up-fly.xpm";
		ft_dstroy_n_put(mlx);
	}
}

void	ft_mv_a(t_mlx *mlx)
{
	if (mlx->map.line[mlx->map.player - 1] == 'E'
		&& mlx->map.collect == 0)
	{
		mlx->map.line[mlx->map.player] = '0';
		mlx->map.steps++;
		ft_game_msgs(mlx, 1);
	}
	if (mlx->map.line[mlx->map.player - 1] == 'X')
		ft_game_msgs(mlx, 3);
	if (mlx->map.line[mlx->map.player - 1] == '0'
		|| mlx->map.line[mlx->map.player - 1] == 'C')
	{
		if (mlx->map.line[mlx->map.player - 1] == 'C')
			mlx->map.collect--;
		mlx->map.steps++;
		mlx->map.line[mlx->map.player] = '0';
		mlx->map.line[mlx->map.player - 1] = 'P';
		mlx->map.p_path = "srcs/left-fly.xpm";
		ft_dstroy_n_put(mlx);
	}
}

void	ft_mv_s(t_mlx *mlx)
{
	if (mlx->map.line[mlx->map.player + mlx->map.map_width] == 'E'
		&& mlx->map.collect == 0)
	{
		mlx->map.line[mlx->map.player] = '0';
		mlx->map.steps++;
		ft_game_msgs(mlx, 1);
	}
	if (mlx->map.line[mlx->map.player + mlx->map.map_width] == 'X')
		ft_game_msgs(mlx, 3);
	if (mlx->map.line[mlx->map.player + mlx->map.map_width] == '0'
		|| mlx->map.line[mlx->map.player + mlx->map.map_width] == 'C')
	{
		if (mlx->map.line[mlx->map.player + mlx->map.map_width] == 'C')
			mlx->map.collect--;
		mlx->map.steps++;
		mlx->map.line[mlx->map.player] = '0';
		mlx->map.line[mlx->map.player + mlx->map.map_width] = 'P';
		mlx->map.p_path = "srcs/down-fly.xpm";
		ft_dstroy_n_put(mlx);
	}
}

void	ft_mv_d(t_mlx *mlx)
{
	if (mlx->map.line[mlx->map.player + 1] == 'E'
		&& mlx->map.collect == 0)
	{
		mlx->map.line[mlx->map.player] = '0';
		mlx->map.steps++;
		ft_game_msgs(mlx, 1);
	}
	if (mlx->map.line[mlx->map.player + 1] == 'X')
		ft_game_msgs(mlx, 3);
	if (mlx->map.line[mlx->map.player + 1] == '0'
		|| mlx->map.line[mlx->map.player + 1] == 'C')
	{
		if (mlx->map.line[mlx->map.player + 1] == 'C')
			mlx->map.collect--;
		mlx->map.steps++;
		mlx->map.line[mlx->map.player] = '0';
		mlx->map.line[mlx->map.player + 1] = 'P';
		mlx->map.p_path = "srcs/right-fly.xpm";
		ft_dstroy_n_put(mlx);
	}
}
