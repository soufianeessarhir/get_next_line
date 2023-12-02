/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 05:30:11 by sessarhi          #+#    #+#             */
/*   Updated: 2023/12/02 13:18:48 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*haha(char *s, char **str,int *flag)
{
    s = ft_substr(*str, 0, ft_strlen(*str));
	*flag = 0;
    free(*str);
    return s;
}
char *ft_backup(char *str,char *buff,int newline)
{
	char *backup;
	free(buff);
	backup = ft_substr(str,newline,ft_strlen(str) - newline);
	free(str);
	return backup;
}
char *get_next_line(int fd)
{
    char *buff;
    char *s;
    static char *str;
	int newline;
	static int flag;

	flag = 1;
    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return NULL;
    while (flag && read(fd, buff, BUFFER_SIZE) >= 0)
    {
        buff[BUFFER_SIZE] = '\0';
        str = ft_strjoin(str, buff);
        newline = ft_strchr(str, '\n');
        if (newline != -1 && flag)
        {
            s = ft_substr(str, 0, newline);
            str = ft_backup(str,buff,newline);
            return s;
        }
		else if (str && flag && newline == -1)
			return(haha(s,&str,&flag));
    }
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
