/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:28:50 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/16 17:29:19 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n' || buff[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	ft_join_to_stash(char **stash, char	*buff, int nread)
{
	int		i;
	int		j;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * ((int)ft_strlen(*stash) + nread + 1));
	if (!temp)
		return (free(temp));
	i = 0;
	if (*stash != NULL)
	{
		while (*(*stash + i))
		{
			temp[i] = *(*stash + i);
			i++;
		}
	}
	j = -1;
	while (++j < nread)
		temp[i + j] = buff[j];
	temp[i + j] = '\0';
	free(*stash);
	*stash = temp;
	return ;
}

void	ft_clean_the_corpse(char **stash, int i)
{
	char	*temp;
	int		j;

	j = 0;
	if (*stash == NULL)
		return ;
	temp = (char *)malloc(sizeof(char) * ((int)ft_strlen(*stash) - i + 1));
	if (!temp)
	{
		free(temp);
		return ;
	}
	while (*(*stash + i))
	{
		temp[j] = *(*stash + i);
		j++;
		i++;
	}
	temp[j] = '\0';
	free(*stash);
	*stash = temp;
	return ;
}
