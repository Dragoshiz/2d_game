/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:09:57 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/16 15:04:37 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Description
	Allocates (with malloc(3)) and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of maximum size ’len’.
*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*dest;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup_nonl(""));
	dest = malloc(sizeof(char) * len + 1);
	if (!dest || *s == '\0')
		return (NULL);
	dest[i] = s[start];
	while (i < len)
	{
		if (s[start] == '\0')
			break ;
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
