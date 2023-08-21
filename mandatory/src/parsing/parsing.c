/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:21:33 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/28 17:10:54 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_texture(t_cub3d_data *cub, char *line, int key, int i)
{
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else if (line[i] == '\n' || line[i] == '\0')
			return (ft_error(TEXTURE_ERROR));
		else
		{
			return (process_texture(cub, line, key, i));
		}
	}
	return (ft_error(TEXTURE_ERROR));
}

int	get_key(char *line)
{
	if (!line || !line[0])
		return (-1);
	if (line[0] == 'N' && line[1] == 'O')
		return (free(line), T_NO);
	else if (line[0] == 'S' && line[1] == 'O')
		return (free(line), T_SO);
	else if (line[0] == 'W' && line[1] == 'E')
		return (free(line), T_WE);
	else if (line[0] == 'E' && line[1] == 'A')
		return (free(line), T_EA);
	else if (line[0] == 'F')
		return (free(line), C_F);
	else if (line[0] == 'C')
		return (free(line), C_C);
	else if (line[0] == '1')
		return (free(line), M_W);
	else if (line[0] == '\n')
		return (free(line), RET_LINE);
	else
		return (free(line), FAILURE);
}

int	check_lines(t_cub3d_data *cub, char *line, int i, int key)
{
	char	*tmp;

	tmp = ft_strtrim(line, " ");
	if (tmp[0] == '\0' && cub->m_index == 0)
		return (FAILURE);
	key = get_key(ft_strtrim(tmp, "\t"));
	free(tmp);
	if (key >= T_NO && key <= C_C)
	{
		tmp = ft_strtrim(line, " ");
		i = check_texture(cub, ft_strtrim(tmp, "\t"), key, 2);
		return (free(tmp), i);
	}
	else if (key == RET_LINE && cub->m_index != 0)
		return (cub->line = ft_strjoin(cub->line, line), SUCCESS);
	else if (key == RET_LINE && cub->m_index == 0)
		return (SUCCESS);
	else if (key == M_W && cub->t_index == 6)
		return (cub->m_index++, cub->line = ft_strjoin(cub->line, line), \
			SUCCESS);
	if (line[ft_strlen(line)] == '\0' && line[ft_strlen(line) - 1] != '\n')
		return (SUCCESS);
	return (ft_error(CONFIG_ERROR));
}

int	read_map(t_cub3d_data *cub, char *av, int fd)
{
	char	*line;
	int		i;

	i = 0;
	(void)av;
	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
	while (line)
	{
		if (check_lines(cub, line, 0, 0) == -1)
		{
			free(line);
			return (FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (check_map(cub, 0) == FAILURE)
		return (ft_error("MAP ERROR"));
	return (SUCCESS);
}

int	map_parsing(t_cub3d_data *cub, int ac, char **av)
{
	int	fd;

	if (ac != 2 || (cub_file(av[1]) == -1))
		return (ft_error(INVALIDE_ARGS));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(NON_EXIT_FILE));
	init_data(cub);
	if (read_map(cub, av[1], fd) == -1)
		return (FAILURE);
	return (SUCCESS);
}
