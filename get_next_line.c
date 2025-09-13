/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:23:46 by malhassa          #+#    #+#             */
/*   Updated: 2025/09/12 17:11:50 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;


	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	lentillfound(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*readmee(int fd,char *buffer,char *remaining)
{
	ssize_t		bytes;

	bytes = 1;
	buffer[0] = '\0';
	if (!remaining)
		remaining = ft_strdup("");
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			remaining = NULL;
			return (NULL);
		}
		buffer[bytes] = '\0';
		remaining = ft_fstrjoin(remaining, buffer);  
	}
	return (remaining);
}

char	*get_next_line(int fd)
{ 
	static char	*remaining;
	char		*buffer;
	char		*returnedstr;
	
	buffer = malloc(BUFFER_SIZE + 1);
	if(!buffer)
		return (NULL);
	remaining = readmee(fd,buffer,remaining);
	if (!remaining || *remaining == '\0' )
	{
		free(remaining);
		free(buffer);
		return (NULL);
	}
	returnedstr = getfirstline(remaining);
	if (!returnedstr)
	{
		free(remaining);
		free(buffer);
		return (NULL);
	}
	remaining = returnremaining(remaining);
	free(buffer);
	if(!remaining)
		free(remaining);
	return (returnedstr);
}

int	main(void)
{
	int fd;
	char *line;
	
	fd = open("newfile.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {		
        printf("%s", line);
        free(line);
    }
	close(fd);	
}