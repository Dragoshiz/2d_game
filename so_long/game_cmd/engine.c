/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:06:55 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/20 14:40:32 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//destroys img and renders it + counts steps on both display and shell
void	ft_dstroy_n_put(t_mlx *mlx)
{
	int		i;
	char	*c;

	i = 0;
	c = ft_itoa(mlx->map.steps);
	while (mlx->map.line[i++])
		if (mlx->map.line[i] == 'P')
			mlx->map.player = i;
	ft_put_tiles(mlx);
	mlx_destroy_image(mlx->ptr, mlx->img);
	ft_put_all(mlx);
	mlx_string_put(mlx->ptr, mlx->window, 10, 10, 0x0, c);
	free(c);
}

int	ft_game_msgs(t_mlx *mlx, int msg)
{
	if (msg == 1)
		write(1, "YOU WON!", 8);
	if (msg == 2)
		write(1, "Exited game!", 12);
	if (msg == 3)
		write(1, "You touched the enemey, GAME OVER!", 34);
	mlx_destroy_window(mlx->ptr, mlx->window);
	free(mlx->ptr);
	free(mlx->map.line);
	exit(0);
	return (0);
}

//when pressing x
int	ft_x(t_mlx *mlx)
{
	write(1, "Exited game!", 12);
	mlx_destroy_window(mlx->ptr, mlx->window);
	free(mlx->ptr);
	free(mlx->map.line);
	exit(0);
	return (0);
}

//Check the key pressed
int	ft_keypress(int key, t_mlx *mlx)
{
	if (key == ESC)
		ft_x(mlx);
	else if (key == W || key == UP)
		ft_mv_w(mlx);
	else if (key == A || key == LEFT)
		ft_mv_a(mlx);
	else if (key == S || key == DOWN)
		ft_mv_s(mlx);
	else if (key == D || key == RIGHT)
		ft_mv_d(mlx);
	return (0);
}
