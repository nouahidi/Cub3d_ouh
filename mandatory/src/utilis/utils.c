/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <lsabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:21:53 by lsabik            #+#    #+#             */
/*   Updated: 2023/07/26 14:22:42 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1);
	res = ft_calloc(1, sizeof(char) * (len + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		res[len++] = s2[i++];
	return (res[len] = '\0', free (s1), res);
}

static int	check_set(char s1, char *set)
{
	while (*set)
	{
		if (*set == s1)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*str;
	size_t	first;
	size_t	last;

	first = 0;
	if (!s1 || !set)
		return (NULL);
	last = ft_strlen(s1) - 1;
	while (s1 && check_set(s1[first], set))
		first++;
	while (check_set(s1[last], set) && first < last)
		last--;
	str = ft_substr(s1, first, (last - first + 1));
	if (!str)
		return (NULL);
	return (str);
}
