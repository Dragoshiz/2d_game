/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:40:29 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/30 11:45:37 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Funcion to put images accordingly
static void	ft_put_xpm(char c, t_mlx *mlx)
{
	if (c == '1')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, WALL,
				&mlx->map.width, &mlx->map.height);
	if (c == 'C' && mlx->map.collect != 0)
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, COLLECT,
				&mlx->map.width, &mlx->map.height);
	if (c == 'E' && mlx->map.collect != 0)
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, EXITC,
				&mlx->map.width, &mlx->map.height);
	if (c == 'E' && mlx->map.collect == 0)
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, "srcs/o-door.xpm",
				&mlx->map.width, &mlx->map.height);
	if (c == 'P')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, mlx->map.p_path,
				&mlx->map.width, &mlx->map.height);
	if (c == 'X')
		mlx->img = mlx_xpm_file_to_image(mlx->ptr, mlx->map.x_path,
				&mlx->map.width, &mlx->map.height);
}

//Function to render the background image
void	ft_put_tiles(t_mlx *mlx)
{
	int		i;
	size_t	x;
	int		y;

	mlx->img = mlx_xpm_file_to_image(mlx->ptr, TILE,
			&mlx->map.width, &mlx->map.height);
	i = 0;
	x = 0;
	y = 0;
	while (mlx->map.line[i])
	{
		mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img, x, y);
		x += 64;
		if (x == 64 * mlx->map.map_width)
		{
			y += 64;
			x = 0;
		}
		i++;
	}
}

//Function to put all images
void	ft_put_all(t_mlx *mlx)
{
	int		i;
	size_t	x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (mlx->map.line[i])
	{
		if (mlx->map.line[i] != '0')
		{
			ft_put_xpm(mlx->map.line[i], mlx);
			mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img, x, y);
			mlx_destroy_image(mlx->ptr, mlx->img);
		}
		x += 64;
		if (x == 64 * mlx->map.map_width)
		{
			y += 64;
			x = 0;
		}
		i++;
	}
}

//funct for the loop hook, it changes the enemy img path every n times
int	ft_loop(t_mlx *mlx)
{
	static int	i;

	ft_dstroy_n_put(mlx);
	if (i == 40)
		i = 0;
	if (i == 10)
		mlx->map.x_path = "srcs/web4.xpm";
	if (i == 20)
		mlx->map.x_path = "srcs/web3.xpm";
	if (i == 30)
		mlx->map.x_path = "srcs/web.xpm";
	if (i == 39)
		mlx->map.x_path = "srcs/web2.xpm";
	i++;
	return (0);
}

void	ft_start(t_mlx *mlx)
{
	mlx_hook(mlx->window, 17, 0L, ft_x, mlx);
	mlx_loop_hook(mlx->ptr, &ft_loop, mlx);
	mlx_hook(mlx->window, 2, (1L << 0), ft_keypress, mlx);
	mlx_loop(mlx->ptr);
}
