/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmunoz- <crmunoz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:42:42 by crmunoz-          #+#    #+#             */
/*   Updated: 2024/01/29 15:40:58 by crmunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_free_line(char *text)
{
	char	*temptext;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!text)
		return (NULL);
	while (text[i] != '\n')
		i++;
	temptext = (char *)malloc(1 + ft_strlen(text) - i);
	if (temptext == NULL)
		return (NULL);
	i++;
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
	if (!text)
		return (NULL);
	while (text[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	line[i] = text[i];
	line[++i] = '\0';
	return (line);
}

char	*ft_final_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	while (text[i])
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (text[i])
	{
		line[i] = text[i];
		i++;
	}
	line[i] = '\0';
	free (text);
	return (line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*text;
	int			bytesread;
	char		*line;
	char		*auxtext;

	line = NULL;
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread == -1)
		return (NULL);
	buffer[bytesread] = '\0';
	if (!text)
		text = ft_strdup(buffer);
	else
	{
		auxtext = ft_strjoin(text, buffer);
		free(text);
		text = auxtext;
	}
	if ((ft_strchr(text, '\n') == -1) && bytesread > 0)
		return (get_next_line(fd));
	else if (bytesread == 0 && text != NULL)
	{
		if (line)
			free (line);
		line = ft_final_line(text);
		text = NULL;
		return (line);
	}
	else if (bytesread == 0 && text == NULL)
		return (NULL);
	else
	{
		if (line)
			free (line);
		line = ft_malloc_line(text);
		text = ft_free_line(text);
		return (line);
	}
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main()
{
	int fd = open ("hola", O_RDONLY);
	printf("1. La puta función de los cojones: %s\n", get_next_line(fd));
	printf("2. La puta función de los cojones: %s\n", get_next_line(fd));
	printf("3. La puta función de los cojones: %s\n", get_next_line(fd));
}*/


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