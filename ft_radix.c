/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:15:26 by nilamber          #+#    #+#             */
/*   Updated: 2024/09/30 14:57:11 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	snowplow(t_list **a, t_list **b, t_list *mp3)
{
	int	count;

	count = lst_count(*a);
	while (mp3 -> pos != 0)
	{
		if (count - mp3 -> pos > count / 2)
			rotate(a, 1);
		else
			rev_rotate(a, 1);
		positioner(*a);
	}
	push(a, b, 1);
	positioner(*a);
}

void	reorderator(t_list **a, t_list **b)
{
	int		count;
	t_list	*low;

	(void) b;
	low = lowest_node_1(*a);
	count = lst_count(*a);
	while (low -> pos != 0)
	{
		while (low -> pos > 0)
		{
			if (count - low -> pos > count / 2)
				rotate(a, 1);
			else
				rev_rotate(a, 1);
			positioner(*a);
		}
		if (count == 2)
			break ;
		count = lst_count(*a);
	}
}

void	pba(t_list **b, t_list **a)
{
	while ((*b)-> status)
		push(b, a, 2);
	positioner(*a);
}

int	max_bin_l(int count)
{
	int	i;

	i = 31;
	while (i && (!((count >> i) & 1)))
		i--;
	return (i + 1);
}

void	radix(t_list **a, t_list **b, int mbl)
{
	t_list	*mp3;
	t_list	*tmp;
	int		i;

	i = 0;
	while (i < mbl)
	{
		mp3 = *a;
		pos1t1oner(*a, i);
		while (mp3)
		{
			if (!((mp3 -> index >> i) & 1))
			{
				tmp = mp3;
				mp3 = mp3 -> next;
				snowplow(a, b, tmp);
			}
			else
				mp3 = mp3 -> next;
		}
		reorderator(a, b);
		pba(b, a);
		i++;
	}
}
