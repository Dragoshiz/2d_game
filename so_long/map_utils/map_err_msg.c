/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_err_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:14:31 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/20 10:44:40 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_errmsgs(t_mlx *mlx, int error)
{
	write(1, "Error\n", 6);
	if (error == 1)
		write(1, "The map must contain at least 1 E, 1 C, and only 1 P", 52);
	if (error == 2)
		write(1, "Wall must be rectangular and closed by 1s", 41);
	if (error == 3)
		write(1, "Wrong simbol used! Simbols allowed PEC10X", 41);
	if (error == 4)
		write(1, "Error with the map", 18);
	if (error == 5)
		write(1, "Map must be with a .ber extension.", 34);
	free(mlx->ptr);
	free(mlx->map.line);
	exit(0);
}
