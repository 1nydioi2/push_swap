/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:07:37 by nilamber          #+#    #+#             */
/*   Updated: 2024/09/19 18:06:22 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	phone(int *tab, int count, int argc)
{
	t_list	*a;
	t_list	*b;

	a = arrayst(count, tab);
	free(tab);
	indexator(a);
	prin(a, "lst a");
	b = blst(count);
	if (alr_sorted(a))
	{
		liberator (a);
		liberator (b);
		return;
	}
	if (argc == 3)
		swap(&a, 3);
	if (argc == 4)
		three(&a, 0);
	else if (argc == 5)
		four(&a, &b, 0);
	else if (argc == 6)
		five (&a, &b);
	prin(a, "lst a");
	liberator (a);
	liberator (b);
}
