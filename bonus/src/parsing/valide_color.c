/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:25:38 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/15 12:33:33 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_comma( char *line)
{
	int	comma;
	int	i;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (ft_error("Invalid color"));
	else if (comma == 2 && line[i - 2] == ',')
		return (ft_error("Invalid color"));
	return (SUCCESS);
}

t_map_color	*check_range(char *line)
{
	t_map_color	*color;
	char		**str;
	int			i;

	i = 0;
	color = ft_calloc(1, sizeof(t_map_color));
	str = NULL;
	str = ft_split(line, ',');
	color->b = ft_atoi(str[0]);
	color->g = ft_atoi(str[1]);
	color->r = ft_atoi(str[2]);
	i = 0;
	ft_free(str, 3);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
	{
		ft_error("Invalid color");
		exit(FAILURE);
	}
	return (color);
}

t_map_color	*valide_color(char *str)
{
	t_map_color	*color;

	if (check_comma(str) == FAILURE)
		exit(FAILURE);
	color = check_range(str);
	free(str);
	return (color);
}
