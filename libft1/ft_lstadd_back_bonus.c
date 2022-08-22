/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:27:27 by enunez-n          #+#    #+#             */
/*   Updated: 2022/04/27 13:39:07 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstptr;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			lstptr = ft_lstlast(*lst);
			lstptr->next = new;
		}
	}
}
