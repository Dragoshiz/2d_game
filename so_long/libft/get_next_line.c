/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:31:38 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/10 16:31:41 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_n_save(int fd, char *save)
{
	char	*buffer;
	int		readval;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	readval = 1;
	while (!ft_strchr(save, '\n') && readval != 0)
	{
		readval = read(fd, buffer, BUFFER_SIZE);
		if (readval == 0)
			break ;
		if (readval == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readval] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*ft_get_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{	
		line[i] = save[i];
		i++;
	}
	return (line);
}

char	*ft_update_save(char *save)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	temp = ft_calloc((ft_strlen(save) - i + 1), sizeof(char));
	if (!temp)
		return (NULL);
	j = 0;
	while (save[i])
		temp[j++] = save[i++];
	free(save);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_n_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_update_save(save);
	return (line);
}
