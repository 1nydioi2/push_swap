/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:59:22 by nilamber          #+#    #+#             */
/*   Updated: 2024/09/30 14:00:53 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	alr_sorted(t_list *a)
{
	while (a -> next)
	{
		if (a -> index > a -> next -> index)
			return (0);
		a = a -> next;
	}
	return (1);
}

void	three(t_list **a, int p)
{
	if ((*a)-> index == (1 + p) && (*a)-> next -> index == (0 + p))
		swap(a, 1);
	else if ((*a)-> index == (1 + p) && (*a)-> next -> index == (2 + p))
		rev_rotate(a, 1);
	else if ((*a)-> index == (2 + p) && (*a)-> next -> index == (0 + p))
		rotate(a, 1);
	else if ((*a)-> index == (2 + p) && (*a)-> next -> index == (1 + p))
	{
		swap(a, 1);
		rev_rotate(a, 1);
	}
	else if ((*a)-> index == (0 + p) && (*a)-> next -> index == (2 + p))
	{
		rev_rotate(a, 1);
		swap(a, 1);
	}
}

void	four(t_list **a, t_list **b, int p)
{
	if ((*a)-> next -> index == (0 + p))
		swap (a, 1);
	else if ((*a)-> next -> next -> index == (0 + p))
	{
		rotate(a, 1);
		rotate(a, 1);
	}
	else if ((*a)-> next -> next -> next -> index == (0 + p))
		rev_rotate(a, 1);
	push(a, b, 1);
	three(a, (1 + p));
	push(b, a, 2);
}

void	five(t_list **a, t_list **b)
{
	if ((*a)-> next -> index == 0)
		swap (a, 1);
	else if ((*a)-> next -> next -> index == 0)
	{
		rotate(a, 1);
		rotate(a, 1);
	}
	else if ((*a)-> next -> next -> next -> index == 0)
	{
		rev_rotate(a, 1);
		rev_rotate(a, 1);
	}
	else if ((*a)-> next -> next -> next -> next -> index == 0)
		rev_rotate(a, 1);
	push(a, b, 1);
	four(a, b, 1);
	push(b, a, 2);
}
