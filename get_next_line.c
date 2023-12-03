/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 05:30:11 by sessarhi          #+#    #+#             */
/*   Updated: 2023/12/03 19:41:09 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>


char	*haha(char *s, char **str)
{
    s = ft_substr(*str, 0, ft_strlen(*str));
    free(*str);
    return s;
}

char *ft_backup(char **str,int newline)
{
	char *backup;
	
	backup = ft_substr(*str,newline,ft_strlen(*str) - newline);
	free(*str);
	*str = NULL;
	return backup;
}
char *haha1(char **str, int i)
{
	 char *s = ft_substr(*str, 0, i);
	 *str = ft_backup(str,i);
	 return s;
}

char *get_next_line(int fd)
{
    char *buff;
    char *s = NULL;
    static char *str;
	int newline;

	if((fd > OPEN_MAX && BUFFER_SIZE <= 0) || fd < 0)
		return NULL;
    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return NULL;
	if(!str)
		str = ft_strdup("");
		int rd = read(fd, buff, BUFFER_SIZE);
		if(rd == -1)
			return (NULL);
    while (fd <= 1024 && rd >= 0)
    {
        buff[rd] = '\0';
		if(!str[0]  && !rd)
			break;
        str = ft_strjoin(str, buff);
        newline = ft_strchr(str, '\n');
        if (newline != -42)
        {
			free(buff);
			return (haha1(&str, newline));
        }
		else if (!rd)
		{
			free(buff);
			return(haha(s,&str));
		}
		rd = read(fd, buff, BUFFER_SIZE); 
    }
	free(buff);
    return NULL;
}
// int main ()
// {
// 	int fd = open("text.txt",O_RDONLY);
// 		printf("%s", get_next_line(fd));
// 		printf("%s", get_next_line(fd));
// 		printf("%s", get_next_line(fd));
// 		printf("%s", get_next_line(fd));
// 		printf("%s", get_next_line(fd));
// 		printf("%s", get_next_line(fd));
// 		printf("%s", get_next_line(fd));	
// }