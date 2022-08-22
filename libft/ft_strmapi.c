/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:10:48 by enunez-n          #+#    #+#             */
/*   Updated: 2022/04/26 10:42:47 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*applied;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	applied = malloc(sizeof(char) * (len + 1));
	if (!applied)
		return (NULL);
	len = 0;
	while (s[len])
	{
		applied[len] = (*f)(len, s[len]);
		len++;
	}
	applied[len] = '\0';
	return (applied);
}
