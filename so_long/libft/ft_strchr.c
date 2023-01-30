/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:56:46 by dimbrea           #+#    #+#             */
/*   Updated: 2022/05/10 13:29:14 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The  strchr()  function  returns  a  pointer  to the first 
occurrence of the character c in the string s.
Here "character" means "byte"; these functions do not work with wide 
or multibyte characters.
*/
#include "libft.h"

char	*ft_strchr(char *buffer, char c)
{
	if (!buffer)
		return (NULL);
	while (*buffer)
	{
		if (*buffer == c)
			return (buffer);
		buffer++;
	}
	if (c == '\0' && *buffer == '\0')
		return (buffer);
	return (NULL);
}
