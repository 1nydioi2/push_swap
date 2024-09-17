/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:07:37 by nilamber          #+#    #+#             */
/*   Updated: 2024/09/17 19:04:37 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chtitator(int chti, int *tab, int count, int index)
{
	int	i;
	
	(void) count;
	i = -1;
	while (++i <= index)
	{
		if (chti == tab[i])
			return (1);
	}
	return (0);
}

void	tabulator(int *tab, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		tab[i] = 0;
}
