/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:47:43 by sessarhi          #+#    #+#             */
/*   Updated: 2023/12/07 11:02:30 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_backup(char **str, int newline)
{
	char	*backup;
	int		len;

	len = ft_strlen(*str);
	backup = ft_substr(*str, newline, len - newline);
	free(*str);
	*str = NULL;
	return (backup);
}

char	*ft_manage(char **str, int i)
{
	char	*s;

	s = ft_substr(*str, 0, i + 1);
	*str = ft_backup(str, i + 1);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str[OPEN_MAX];
	int			newline;
	int			rd;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (!str[fd])
		str[fd] = ft_strdup("");
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	rd = read(fd, buff, BUFFER_SIZE);
	while (rd >= 0)
	{
		buff[rd] = '\0';
		if (!str[fd][0] && !rd)
			break ;
		str[fd] = ft_strjoin(str[fd], buff);
		newline = ft_strchr(str[fd], '\n');
		if (newline != -42)
			return (free(buff), ft_manage(&str[fd], newline));
		else if (!rd)
			return (free(buff), ft_backup(&str[fd], 0));
		rd = read(fd, buff, BUFFER_SIZE);
	}
	return (free(str[fd]), free(buff), str[fd] = NULL, NULL);
}
