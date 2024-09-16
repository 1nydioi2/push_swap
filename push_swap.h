/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:37:30 by nilamber          #+#    #+#             */
/*   Updated: 2024/09/14 18:42:01 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_list
{
	int				content;
	int				index;
	int				status;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;
t_list			*arrayst(int count, int *tab);
t_list			*blst(int count);
void			liberator(t_list *lst);
void			swap(t_list **lst);
void			push(t_list **alpha, t_list **beta);
void			rotate(t_list **lst);
void			rev_rotate(t_list **lst);
void			prin(t_list *lst, char *str);
void			ss(t_list **a, t_list **b);
void			rr(t_list **a, t_list **b);
void			rrr(t_list **a, t_list **b);
void			indexator(t_list *lst, int count);
#endif
