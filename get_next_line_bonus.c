/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:47:43 by sessarhi          #+#    #+#             */
/*   Updated: 2023/12/06 11:49:26 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"


int main ()
{
	int fd = open("1",O_RDONLY);
	int fd1 = open("2",O_RDONLY);
	printf("%s", get_next_line_bonus(&fd));		
	printf("%s", get_next_line_bonus(&fd1));		
	printf("%s", get_next_line_bonus(&fd));		
	printf("%s", get_next_line_bonus(&fd1));		
}