/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:21:44 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/27 10:38:39 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(size * count);
	if (!str)
		return (0);
	ft_memset(str, 0, size * count);
	return (str);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	char	*res;

	str = ft_calloc(1, sizeof(char) * (ft_strlen(s1) + 1));
	if (!(str))
		return (0);
	res = str;
	while (*s1)
	{
		*str = *s1;
		s1++;
		str++;
	}
	*str = '\0';
	return (res);
}

char	*extract_line(char **static_buff)
{
	char	*tmp;
	char	*line;
	int		i;

	if (*static_buff == 0 || **static_buff == 0)
		return (0);
	i = 0;
	i = ft_strchr(*static_buff, '\n');
	line = ft_substr(*static_buff, 0, i + 1);
	tmp = ft_strdup(&(*static_buff)[i + 1]);
	if (tmp[0] == '\0')
	{
		free(tmp);
		tmp = 0;
	}
	free(*static_buff);
	*static_buff = tmp;
	return (line);
}

int	read_lines(int fd, char **static_buff, int buffer_size)
{
	int		readed;
	char	*buff;

	readed = 1;
	buff = ft_calloc(1, sizeof(char) * buffer_size + 1);
	if (!buff)
		return (0);
	while (ft_strchr(*static_buff, '\n') == -1 && readed)
	{
		readed = read(fd, buff, buffer_size);
		if (readed <= 0)
		{
			free(buff);
			return (0);
		}
		buff[readed] = '\0';
		*static_buff = ft_strjoin(*static_buff, buff);
	}
	free(buff);
	return (readed);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			readed;
	static char	*static_buff[OPEN_MAX];
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	readed = read_lines(fd, &static_buff[fd], 80);
	if (!readed)
	{
		tmp = static_buff[fd];
		static_buff[fd] = 0;
		return (tmp);
	}
	if (readed == -1)
		return (NULL);
	line = extract_line(&static_buff[fd]);
	return (line);
}
