/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 08:42:47 by enunez-n          #+#    #+#             */
/*   Updated: 2022/04/28 12:16:08 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*bridge;

	newlst = NULL;
	while (lst)
	{
		bridge = ft_lstnew(f(lst->content));
		if (!bridge)
		{
			del(newlst);
			free(newlst);
			free(bridge);
			return (NULL);
		}
		ft_lstadd_back(&newlst, bridge);
		lst = lst->next;
	}
	return (newlst);
}
