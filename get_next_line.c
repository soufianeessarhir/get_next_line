/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 05:30:11 by sessarhi          #+#    #+#             */
/*   Updated: 2023/12/01 11:47:01 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *get_next_line(int fd)
{
	static char *str;
	// int line;
	char *s;
	char *buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buff[BUFFER_SIZE + 1] = '\0';
	while (read(fd,buff,BUFFER_SIZE)>= 0)
	{
		ft_strjoin(str,buff);
		line = ft_strchr(str,'\n');
		if (line != -1)
		{
			
		}
		
	}
	
}
int main ()
{
	int fd = open("text.txt",O_RDONLY);
	printf("%s", get_next_line(fd));
	
}