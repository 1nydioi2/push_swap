/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:00:17 by nilamber          #+#    #+#             */
/*   Updated: 2024/09/14 18:39:27 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	if ((*lst) -> status && (*lst) -> next -> status)
	{
		(*lst) -> next -> prev = (*lst) -> prev;
		(*lst) -> prev = (*lst) -> next;
		(*lst) -> next = (*lst) -> next -> next;
		(*lst) -> prev -> next = *lst;
		*lst = (*lst) -> prev;
	}
	return;
}

void	push(t_list **alpha, t_list **beta)
{
	if ((*alpha) -> status)
	{
		(*beta) -> prev = *alpha;
		(*alpha) -> next -> prev = (*alpha) -> prev;
		*alpha = (*alpha) -> next;
		(*beta) -> prev -> next = *beta;
		*beta = (*beta) -> prev;
	}
}

void	rotate(t_list **lst)
{
	t_list	*tail;

	if ((*lst) -> status && (*lst) -> next -> status)
	{
		tail = *lst;
		while (tail -> next)
			tail = tail -> next;
		tail -> next = *lst;
		(*lst) -> next -> prev = (*lst) -> prev;
		*lst = (*lst) -> next;
		tail -> next -> prev = tail;
		tail -> next -> next = NULL;
	}
}

void	rev_rotate(t_list **lst)
{
	t_list *tail;

	if ((*lst) -> status && (*lst) -> next -> status)
	{
		tail = *lst;
		while (tail -> next)
			tail = tail -> next;
		tail -> prev -> next = tail -> next;
		tail -> prev = tail -> next;
		(*lst) -> prev = tail;
		tail -> next = *lst;
		*lst = tail;
	}
}




















































