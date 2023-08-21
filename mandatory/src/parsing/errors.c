/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:55:18 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/28 12:43:54 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	empty_line(t_cub3d_data *cub)
{
	int	i;

	i = 0;
	if (!cub->line)
		return (FAILURE);
	if (ft_isspace(cub->line[i]))
	{
		while (ft_isspace(cub->line[i]))
			i++;
		if (!cub->line)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_error(char *s)
{
	ft_putstr("\033[1;31mError!!\n");
	ft_putstr(s);
	ft_putstr("\n");
	return (FAILURE);
}
