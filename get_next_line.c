/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:42:42 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/01/23 20:22:53 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_line(char *text)
{
	char	*temptext;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (text[i] != '\n')
		i++;
	len = ft_strlen(text);
	len = len - i;
	temptext = malloc(sizeof(char) * (len + 1));
	while (text[i + j] != '\0')
	{
		temptext[j] = text[i + j];
		j++;
	}
	temptext[i + j] = '\0';
	free(text);
	return (temptext);
}

char	*ft_malloc_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	while (text[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*text;
	int			bytesread;
	char		*line;

	line = NULL;
	text = NULL;
	if (!fd)
		return (NULL);
	bytesread = read(fd, buffer, BUFFER_SIZE);

	if (bytesread > 0)
	{
		buffer[bytesread] = '\0';
		if (!text)
			text = ft_strdup(buffer);
		else
			text = ft_strjoin(text, buffer);
		if (text == NULL)
			return (NULL);
		if (ft_strchr(text, '\n') == NULL)
			get_next_line(fd);
		else
		{
			if (line)
				free(line);
			line = ft_malloc_line(text);
			text = ft_free_line(text);
		}
	}
	else
		return (NULL);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int	main(){
	int fd = open ("hola", O_RDONLY);
	printf("%s", get_next_line(fd));
}


/*
#include <stdio.h>
int	main(){
	int str[22];
	int	i = sizeof(str);
	str[0] = 1;
	str[1] = 2;
	printf("%i\n%i\n%i", i, str[1], *str);
}
*/