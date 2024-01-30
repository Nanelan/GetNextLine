/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:57:22 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/01/30 21:11:23 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*schar;

	i = 0;
	schar = (char *) s;
	if (schar)
	{
		while (schar[i] != '\0')
			i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(size * count);
	if (ptr == NULL)
		return (0);
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_calloc(1, 1);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	j = 0;
	s3 = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!s3)
		return (0);
	while (i < (s1len))
	{
		s3[i] = s1[i];
		i++;
	}
	while ((i + j) < (s1len + s2len))
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	free (s1);
	return (s3);
}

int	ft_strchr(const char *s, int c)
{
	unsigned char	d;
	int				i;

	i = 0;
	d = (unsigned char)c;
	while (*s != d && *s != 0)
	{
		s++;
		i++;
	}
	if (*s == d)
		return (i);
	return (-1);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;
	int		s1len;

	i = 0;
	s1len = ft_strlen(s1);
	dest = malloc((sizeof(char) * s1len) + 1);
	if (dest == NULL)
		return (0);
	while (i < s1len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
