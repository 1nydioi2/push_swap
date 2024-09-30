/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:07:37 by nilamber          #+#    #+#             */
/*   Updated: 2024/09/30 14:28:38 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lowest_node_1(t_list *lst)
{
	t_list	*low;

	low = lst;
	while (lst)
	{
		if (lst -> pos1 < low -> pos1)
			low = lst;
		lst = lst -> next;
	}
	return (low);
}

int	lst_count(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

void	positioner(t_list *lst)
{
	int	ppos;

	ppos = 0;
	while (lst)
	{
		lst -> pos = ppos++;
		lst = lst -> next;
	}
}

void	pos1t1oner(t_list *lst, int i)
{
	int	ppos;

	ppos = 0;
	while (lst)
	{
		if ((lst -> index >> i) & 1)
			lst -> pos1 = ppos++;
		lst = lst -> next;
	}
}

void	phone(int *tab, int count, int argc)
{
	t_list	*a;
	t_list	*b;

	a = arrayst(count, tab);
	free(tab);
	indexator(a);
	b = blst(count);
	if (alr_sorted(a))
		return (liberator(a), liberator(b));
	positioner(a);
	if (argc == 3)
		swap(&a, 3);
	if (argc == 4)
		three(&a, 0);
	else if (argc == 5)
		four(&a, &b, 0);
	else if (argc == 6)
		five (&a, &b);
	else
		radix(&a, &b, max_bin_l(count));
	liberator (a);
	liberator (b);
}
