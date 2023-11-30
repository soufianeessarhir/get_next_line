/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 05:30:11 by sessarhi          #+#    #+#             */
/*   Updated: 2023/11/30 01:08:24 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *buff;
	int i;
	char *s;
	static char *str;


	i = 0;
	while (read(fd , buff, BUFFER_SIZE) != 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		buff[BUFFER_SIZE + 1] = '\0';
		str = ft_strjoin(str,buff);
		if (ft_strchr(str, '\n') != NULL)
		{
			s = ft_substr(str, 0, ft_strchr(str, '\n') - str);
			str = ft_strchr(str, '\n');
			return s;
		}
		free(buff);
	}

	
	return NULL;
}
// int main ()
// {
// 	int fd = open("text.txt",O_RDONLY);

// 		printf("%s\n", get_next_line(fd));
// 		printf("%s\n", get_next_line(fd));
	
// }