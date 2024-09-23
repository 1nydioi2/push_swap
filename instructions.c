/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:00:17 by nilamber          #+#    #+#             */
/*   Updated: 2024/09/23 23:52:50 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, int print)
{
	if ((*lst) -> status && (*lst) -> next -> status)
	{
		(*lst) -> next -> prev = (*lst) -> prev;
		(*lst) -> prev = (*lst) -> next;
		if (print != 3)
			(*lst) -> next -> next -> prev = *lst;
		(*lst) -> next = (*lst) -> next -> next;
		(*lst) -> prev -> next = *lst;
		*lst = (*lst) -> prev;
	}
	if (print == 1 || print == 3)
		write(1, "sa\n", 3);
	if (print == 2)
		write(1, "sb\n", 3);
}

void	push(t_list **alpha, t_list **beta, int print)
{
	if ((*alpha) -> status)
	{
		(*beta) -> prev = *alpha;
		(*alpha) -> next -> prev = (*alpha) -> prev;
		*alpha = (*alpha) -> next;
		(*beta) -> prev -> next = *beta;
		*beta = (*beta) -> prev;
	}
	if (print == 1)
		write(1, "pb\n", 3);
	if (print == 2)
		write(1, "pa\n", 3);
}

void	rotate(t_list **lst, int print)
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
	if (print == 1)
		write(1, "ra\n", 3);
	if (print == 2)
		write(1, "rb\n", 3);
}

void	rev_rotate(t_list **lst, int print)
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
	if (print == 1)
		write(1, "rra\n", 4);
	if (print == 2)
		write(1, "rrb\n", 4);
}




















































