/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 07:58:57 by enunez-n          #+#    #+#             */
/*   Updated: 2022/04/25 13:18:05 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*duplicate;

	duplicate = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!duplicate)
		return (0);
	ft_strlcpy(duplicate, s1, ft_strlen(s1)+1);
	return (duplicate);
}
