/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:15:30 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/24 12:53:10 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	distance(int i, int j, int x, int y)
{
	return (sqrt(pow(x - i, 2) + pow(y - j, 2)));
}

int	check_ch(t_cub3d_data *cub, int bx, int by, char c)
{
	if (cub->matrice[by / (W_DM / 2)][bx / (W_DM / 2)] == c)
		return (1);
	return (0);
}

int	process_texture(t_cub3d_data *cub, char *line, int key, int i)
{
	char	*tmp;

	tmp = ft_strtrim(&line[i], "\n");
	if (key == T_NO && cub->t_no == NULL)
		cub->t_no = ft_strdup(tmp);
	else if (key == T_SO && cub->t_so == NULL)
		cub->t_so = ft_strdup(tmp);
	else if (key == T_WE && cub->t_we == NULL)
		cub->t_we = ft_strdup(tmp);
	else if (key == T_EA && cub->t_ea == NULL)
		cub->t_ea = ft_strdup(tmp);
	else if (key == C_F && cub->c_f == NULL)
		cub->c_f = valide_color(ft_strdup(&line[i]));
	else if (key == C_C && cub->c_c == NULL)
		cub->c_c = valide_color(ft_strdup(&line[i]));
	else
	{
		free(line);
		free(tmp);
		return (ft_error(TEXTURE_ERROR));
	}
	free(line);
	free(tmp);
	cub->t_index++;
	return (SUCCESS);
}
