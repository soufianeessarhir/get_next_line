/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 05:30:11 by sessarhi          #+#    #+#             */
/*   Updated: 2023/12/04 11:54:58 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

char *ft_backup(char **str,int newline);

char *ft_backup(char **str,int newline)
{
	char *backup;
	int len = ft_strlen(*str) ;
	backup = ft_substr(*str,newline,len - newline);
	free(*str);
	*str = NULL;
	return backup;
}
char *haha1(char **str, int i)
{
	 char *s = ft_substr(*str, 0, i+1);
	 *str = ft_backup(str,i+1);
	 return s;
}

char *get_next_line(int fd)
{
    char *buff;
    char *s = NULL;
    static char *str;
	int newline;
	int rd ;
	rd =0;
	if(!str)
		str = ft_strdup("");
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return NULL;
	rd = read(fd, buff, BUFFER_SIZE);
    while (rd >= 0)
    {
		if(!str[0]  && !rd)
			break;
        buff[rd] = '\0';
        str = ft_strjoin(str,buff);
        newline = ft_strchr(str, '\n');
        if (newline != -42)
			return (free(buff),haha1(&str,newline));
		 if (!rd)
			return(free(buff),ft_backup(&str,0));
		rd = read(fd, buff, BUFFER_SIZE); 
    }
	free(buff);
    return NULL;
}
int main ()
{
	int fd = open("text.txt",O_RDONLY);
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));	
}