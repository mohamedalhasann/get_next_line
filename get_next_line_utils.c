/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:42:35 by malhassa          #+#    #+#             */
/*   Updated: 2025/09/12 17:06:44 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fstrjoin(char *s1, char *s2)
{
	int		length;
	int		j;
	char	*ptr;
	char	*old;

	j = 0;
	old = s1;
	length = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(length + 1);
	if (!ptr)
		return (NULL);
	while (*s1)
		ptr[j++] = *s1++;
	while (*s2)
		ptr[j++] = *s2++;
	ptr[j] = '\0';
	free(old);
	return (ptr);
}
char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	length;
	size_t	i;

	i = 0;
	length = ft_strlen(s);
	str = (char *)malloc(length + 1);
	if (str == NULL)
		return (NULL);
	while (i < length)
	{
		str[i] = s[i];
		i++;
	}
	str[length] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	x;

	x = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == x)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == x)
		return ((char *)s + i);
	return (NULL);
}
char	*getfirstline(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(lentillfound(str) + 2);
	if (!temp)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] == '\n' )
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

char	*returnremaining(char *rem)
{
	char	*temp;
	char	*newline;

	if(!rem)
		return (NULL);
	newline = ft_strchr(rem, '\n');
	if (!newline)
		return (NULL);
	newline++;
	temp = malloc(ft_strlen(newline) + 1);
	if (!temp)
		return (NULL);
	strcpy(temp, newline);
	free(rem);
	return (temp);
}
