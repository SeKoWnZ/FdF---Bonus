/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:51:23 by jose-gon          #+#    #+#             */
/*   Updated: 2023/10/04 11:45:23 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*newl;
	void	*tmp;

	newl = 0;
	while (lst)
	{
		tmp = f(lst->content);
		cpy = ft_lstnew(tmp);
		if (!cpy)
		{
			del(tmp);
			ft_lstclear(&newl, del);
			return (0);
		}
		ft_lstadd_back(&newl, cpy);
		lst = lst->next;
	}
	return (newl);
}
