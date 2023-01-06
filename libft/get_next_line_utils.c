/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 07:21:05 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/06 14:16:14 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gstrdup(char *s1, int i)
{
	char	*ret;

	ret = malloc(ft_strlen(s1 + i) + 1);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1 + i, ft_strlen(s1 + i) + 1);
	free(s1);
	return (ret);
}

int	ft_isnl(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dstsize > 0)
	{
		while (src[i])
		{
			if (dstsize > 0 && i < (dstsize - 1))
			{
				dst[j] = src[j];
				j++;
			}
			i++;
		}
		dst[j] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_gstrjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (s1 == 0 || s2 == 0)
		return (0);
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ret == 0)
		return (0);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	return (free(s1), ret);
}
