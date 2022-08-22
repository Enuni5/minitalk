/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 07:22:08 by enunez-n          #+#    #+#             */
/*   Updated: 2022/05/09 09:17:22 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char delim)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] != delim)
			flag = 1;
		if ((str[i] == delim || str[i + 1] == '\0') && flag == 1)
		{
			flag = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*save_words(const char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		words_count;
	int		i;

	if (!s)
		return (NULL);
	words_count = word_count(s, c);
	splitted = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!splitted)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			splitted[i] = save_words(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	splitted[i] = 0;
	return (splitted);
}
