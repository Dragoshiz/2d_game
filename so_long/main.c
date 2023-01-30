/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:40:12 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/20 14:32:33 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc != 2)
	{
		write(1, "Argument missing", 16);
		exit(0);
	}
	mlx.map.map_height = 0;
	mlx.map.steps = 0;
	mlx.map.p_path = "srcs/down-fly.xpm";
	mlx.map.x_path = "srcs/web.xpm";
	ft_get_map(&mlx, argv[1]);
	mlx.ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.ptr, mlx.map.map_width * 64,
			mlx.map.map_height * 64, "so_long");
	ft_start(&mlx);
	free(mlx.map.line);
	return (0);
}
