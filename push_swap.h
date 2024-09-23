/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:37:30 by nilamber          #+#    #+#             */
/*   Updated: 2024/09/23 23:04:41 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_list
{
	int	content;
	int	index;
	int	status;
	int	pos;
	int	pos1;
	struct	s_list	*next;
	struct	s_list	*prev;
}	t_list;
t_list	*arrayst(int count, int *tab);
t_list	*blst(int count);
void	liberator(t_list *lst);
void	swap(t_list **lst, int print);
void	push(t_list **alpha, t_list **beta, int print);
void	rotate(t_list **lst, int print);
void	rev_rotate(t_list **lst, int print);
void	prin(t_list *lst, char *str);
void	ss(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);
void	indexator(t_list *lst);
int	alr_sorted(t_list *a);
void	three(t_list **a, int p);
void	four(t_list **a, t_list **b, int p);
void	five(t_list **a, t_list **b);
void	phone(int *tab, int count, int argc);
void	radix(t_list **a, t_list **b, int count);
void	positioner(t_list *lst);
void	pos1t1oner(t_list *lst, int i);
int	lst_count(t_list *lst);
t_list	*lowest_node_1(t_list *lst);
#endif
