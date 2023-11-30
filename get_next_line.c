/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 05:30:11 by sessarhi          #+#    #+#             */
/*   Updated: 2023/11/30 06:19:40 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *buff;
    char *s;
    static char *str;
	char *newline;
	int i = 0;

    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return NULL;
    while (read(fd, buff, BUFFER_SIZE) > 0)
    {
        buff[BUFFER_SIZE] = '\0';
        str = ft_strjoin(str, buff);
        newline = ft_strchr(str, '\n');
        if (newline != NULL)
        {
            s = ft_substr(str, 0, newline - str);
            str = newline + 1;
            free(buff);
            return s;
        }
    }
    free(buff);
	 if (str)
    {
         s = ft_substr(str, 0, ft_strlen(str));
        free(str);
        return ft_substr(s,0,ft_strlen(s) - BUFFER_SIZE);
    }
    return NULL;
}
int main ()
{
	int fd = open("text.txt",O_RDONLY);

		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));	
		printf("%s\n", get_next_line(fd));	
		printf("%s\n", get_next_line(fd));	

}