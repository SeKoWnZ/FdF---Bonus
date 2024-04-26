/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:45:11 by jose-gon          #+#    #+#             */
/*   Updated: 2024/02/16 17:29:28 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_willy(char	**stash)
{
	free(*stash);
	*stash = NULL;
	return ;
}

static void	ft_read_and_stash(int fd, char **stash, int nread)
{
	char	*buff;

	while (nread != 0)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		nread = read(fd, buff, BUFFER_SIZE);
		if ((*stash == NULL && nread == 0) || nread == -1)
		{
			free(buff);
			return ;
		}
		buff[nread] = '\0';
		ft_join_to_stash(stash, buff, nread);
		if (ft_check_newline(buff))
		{
			free(buff);
			return ;
		}
		free(buff);
	}
	return ;
}

static void	ft_get_da_line(char **stash, char **line)
{
	int	i;
	int	j;

	i = 0;
	if (*stash == NULL)
		return ;
	while (*(*stash + i) && *(*stash + i) != '\n')
		i++;
	if (*(*stash + i) == '\n')
		i++;
	*line = (char *)malloc(sizeof(char) * i + 1);
	if (!(*line))
		return ;
	j = 0;
	while (j < i)
	{
		*(*line + j) = *(*stash + j);
		j++;
	}
	*(*line + j) = '\0';
	ft_clean_the_corpse(stash, i);
	return ;
}

char	*get_next_line(int fd)
{
	static char		*stash[4096];
	char			*line;
	int				nread;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		if (stash[fd] != NULL)
			ft_free_willy(&stash[fd]);
		return (NULL);
	}
	line = NULL;
	nread = 1;
	ft_read_and_stash(fd, &stash[fd], nread);
	if (stash[fd] == NULL)
		return (NULL);
	ft_get_da_line(&stash[fd], &line);
	if (line[0] == '\0')
	{
		ft_free_willy(&stash[fd]);
		free(line);
		return (NULL);
	}
	return (line);
}
