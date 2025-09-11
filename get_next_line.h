/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:24:15 by malhassa          #+#    #+#             */
/*   Updated: 2025/09/11 17:19:22 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

#ifndef BUFFER_SIZE
#   define BUFFER_SIZE 42
#endif
char    *get_next_line(int fd);
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
size_t	ft_strlen(const char *str);
char	*ft_fstrjoin(char  *s1, char  *s2);
char    *returnremaining(char *rem);
char	*ft_strdup(const char *s);
int     lentillfound(char *str);
char	*getfirstline(char *str);
char	*ft_strchr(const char *s, int c);
#endif