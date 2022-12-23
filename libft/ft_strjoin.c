/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:13:43 by jbarbate          #+#    #+#             */
/*   Updated: 2022/11/12 08:44:04 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_t;
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	len_t = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * len_t + 1);
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
	return (ret);
}
