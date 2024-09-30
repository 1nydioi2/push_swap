/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:03:12 by nilamber          #+#    #+#             */
/*   Updated: 2024/09/30 14:42:10 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexator(t_list *lst)
{
	t_list	*t_index;
	t_list	*mp3;
	int		i;

	t_index = lst;
	while (t_index)
	{
		i = 0;
		mp3 = lst;
		while (mp3)
		{
			if (t_index -> content > mp3 -> content)
				i++;
			mp3 = mp3 -> next;
		}
		t_index -> index = i;
		t_index = t_index -> next;
	}
}

void	addnewf(t_list **lst, int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		write(1, "\nMALLOC FAILED\n\n", 16);
		return ;
	}
	new -> content = content;
	new -> next = *lst;
	new -> status = 1;
	(*lst)-> prev = new;
	*lst = new;
}

t_list	*arrayst(int count, int *tab)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (write(1, "\n\n\nmalloc failed\n", 17), NULL);
	head -> next = NULL;
	head -> content = tab[--count];
	head -> status = 1;
	while (--count >= 0)
		addnewf(&head, tab[count]);
	head -> prev = NULL;
	return (head);
}

void	liberator(t_list *lst)
{
	t_list	*tmp;

	while (lst -> next)
	{
		tmp = lst;
		lst = lst -> next;
		free(tmp);
	}
	free(lst);
}

t_list	*blst(int count)
{
	t_list	*b;

	b = malloc(sizeof(t_list));
	if (!b)
		return (write(1, "\n\n\nmalloc failed\n", 17), NULL);
	b -> next = NULL;
	b -> status = 0;
	while (--count > 0)
	{
		b -> prev = malloc(sizeof(t_list));
		if (!b -> prev)
			return (write(1, "\n\n\nmalloc failed\n", 17), NULL);
		b -> prev -> next = b;
		b = b -> prev;
		b -> status = 0;
	}
	b -> prev = NULL;
	return (b);
}
