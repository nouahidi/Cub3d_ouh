/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:16:55 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/15 16:29:41 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_space(char str)
{
	if (str == '\t' || str == ' ')
		return (1);
	return (0);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (n > i)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

void	*ft_realloc(void *ptr, size_t size, size_t old_size)
{
	void	*new_ptr;

	new_ptr = malloc(size + 1);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

int	resizematrice(t_cub3d_data *cub, int num_lines)
{
	int	i;
	int	currentlength;
	int	diff;

	i = 0;
	while (i < num_lines)
	{
		currentlength = ft_strlen(cub->matrice[i]);
		diff = cub->len_i - currentlength;
		if (diff > 0)
		{
			cub->matrice[i] = ft_realloc(cub->matrice[i], \
				(cub->len_i * sizeof(char)), currentlength);
			ft_memset(cub->matrice[i] + currentlength, ' ', diff);
			cub->matrice[i][currentlength + diff] = '\0';
		}
		i++;
	}
	return (num_lines);
}
