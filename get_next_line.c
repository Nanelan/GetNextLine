/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:51:31 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/01/22 13:03:43 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_line(char *text)
{
	char	*temptext;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temptext = NULL;
	while (text[i] != '\n')
		i++;
	while (text[i] != '\0')
	{
		temptext[j] = text[i + j];
		j++;
	}
	free(text);
	return (temptext);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*text;
	int			bytesread;
	int			i;
	char		*line;

	text = NULL;
	line = NULL;
	i = 0;
	bytesread = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	if (bytesread > 0)
	{
		while (buffer[i] != '\n' || buffer[i] == '\0')
		{
			text = ft_strjoin(text, buffer);
			i++;
		}
		if (ft_strchr(text, '\n') == NULL)
			get_next_line(fd);
		else if (*ft_strchr(text, '\n') == '\n')
		{
			i = 0;
			while (text[i] != '\n')
			{
				line[i] = text[i];
				i++;
			}
			text = ft_free_line(text);
		}
	}
	else
		return (NULL);
	return (line);
}

/*
#include <stdio.h>
#include <fcntl.h>
int	main(){
	int fd = open ("hola", O_RDONLY);
	printf("%s", get_next_line(fd));
}
*/

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