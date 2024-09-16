/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:07:37 by nilamber          #+#    #+#             */
/*   Updated: 2024/09/16 19:55:31 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chtitator(int chti, int *tab, int count, int index)
{
	int	i;
	
	(void) count;
	i = -1;
	printf("chti = %d, tab[%d] = %d\n", chti, i, tab[i]);
	while (++i <= index)
	{
		printf("chti = %d, tab[%d] = %d\n", chti, i, tab[i]);
		if (chti == tab[i])
			return (1);
	}
	tab[index] = chti;
	return (0);
}

void	tabulator(int *tab, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		tab[i] = 0;
}
