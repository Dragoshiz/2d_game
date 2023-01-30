/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:46:31 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/10 18:34:13 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
*/
#include "libft.h"

char	*ft_strjoin(char *save, char *buffer)
{
	char	*p;
	int		i;
	int		j;

	if (!save)
		save = ft_calloc(1, sizeof(char));
	if (!save || !buffer)
		return (NULL);
	p = ft_calloc((ft_strlen(save) + ft_strlen(buffer)) + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			break ;
		p[i] = save[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		p[i++] = buffer[j++];
	free(save);
	return (p);
}
