/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 03:55:42 by sessarhi          #+#    #+#             */
/*   Updated: 2023/12/04 13:10:06 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*newstr;
	i = 0;
	j =0;
	newstr = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) )+ 1));
	if (!newstr)
		return (NULL);
	while(s1[i])
	{
		newstr[i] =s1[i];
		i++;
	}
	while(s2[j])
	{
		newstr[ i+j] = s2[j];
		j++;
	}
	newstr[i + j] ='\0';
	free((void*)s1);
	s1 = NULL;
	return ( newstr);
}
int ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i); 
		i++;
	}
	return (-42);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	s_len;

	s_len = ft_strlen(s);
	if (len == 0 || start > s_len)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = *(s + i + start);
		i++;
	}
	str[i] = '\0';
	return (str);
}
char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char ) * (ft_strlen(str) + 1));
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
