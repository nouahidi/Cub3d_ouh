/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:37:31 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/28 11:04:33 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_sides(t_cub3d_data *cub, int i, int j)
{
	if (check_space(cub->matrice[i - 1][j]) == 1)
		return (FAILURE);
	if (check_space(cub->matrice[i + 1][j]) == 1)
		return (FAILURE);
	if (check_space(cub->matrice[i][j - 1]) == 1)
		return (FAILURE);
	if (check_space(cub->matrice[i][j + 1]) == 1)
		return (FAILURE);
	return (SUCCESS);
}

int	valid_char(t_cub3d_data *cub, char c, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		cub->t_index++;
		cub->player_x = j;
		cub->player_y = i;
		cub->player_dir = c;
	}
	if ((c == '1' || c == '0' || c == ' ' || c == 'N' || c == 'S' || c == 'E'\
		|| c == 'W') && cub->t_index < 8)
		return (SUCCESS);
	else
		return (FAILURE);
}

int	cub_file(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ".cub";
	while (s && s[i])
	{
		if (s && s[i] == str[0] && ft_strcmp(s + i, str) == 0)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}
