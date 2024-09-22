/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:15:26 by nilamber          #+#    #+#             */
/*   Updated: 2024/09/22 01:54:49 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	snowplow(t_list **a, t_list **b, t_list *mp3, int count)
{
	while (mp3 -> pos != 0)
	{
		if (mp3 -> pos == 1)
			swap(a, 1);
		else if (count - mp3 -> pos > count / 2)
			rotate(a, 1);
		else
			rev_rotate(a, 1);
		positioner(*a);
	}
	push(a, b, 1);
	positioner(*a);
}

void	pba(t_list **b, t_list **a)
{
	while ((*b) -> status)
		push(b, a, 2);
	printf("\npba done\n\n");
	positioner(*a);
}

int	max_bin_l(int count)
{
	int	i;

	i = 31;
	while (i && (!(count >> i) & 1))
		i--;
	printf("\nmax_bin_l = %d\n", i + 1);
	return (i + 1);
}

void	radix(t_list **a, t_list **b, int count)
{
	t_list *mp3;
	t_list *tmp;
	int	mbl;
	int	i;

	positioner(*a);
	mbl = (max_bin_l(count));
	i = 0;
	while (i < mbl)
	{
		mp3 = *a;
		while (mp3)
		{
			printf("\n\nradix\tmp3 -> index = %d\n", mp3 -> index);
			if (!((mp3 -> index >> i) & 1))
			{
				tmp = mp3;
				mp3 = mp3 -> next;
				snowplow(a, b, tmp, count);
			}
			else
				mp3 = mp3 -> next;
		}
		pba(b, a);
		i++;
	}
}
