/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:27:40 by enunez-n          #+#    #+#             */
/*   Updated: 2022/04/28 09:11:20 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (ft_strlen(s) < start || s == NULL)
	{
		substr = malloc(sizeof(char));
		if (!substr)
			return (0);
		substr[0] = '\0';
		return (substr);
	}
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		substr = malloc(sizeof(char) * (len + 1));
		if (!substr)
			return (0);
		i = 0;
		while (++i - 1 < len)
			substr[i - 1] = s[start + i - 1];
		substr[i - 1] = '\0';
		return (substr);
	}
}
