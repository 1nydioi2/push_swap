#include "push_swap.h"

void	addnewf(t_list **lst, int content, int number)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (write(1, "\n\n\nmalloc failed\n", 17), NULL);
	new -> content = content;
	new -> number = number;
	new -> next = *lst;
	(*lst) -> prev = new; 
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
	head -> number = count;
	while (--count >= 0)
		addnewf(&head, tab[count], count);
	head -> prev = NULL;
	return(head);
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
	t_list *b;
	
	b = malloc(sizeof(t_list));
	if (!b)
		return (write(1, "\n\n\nmalloc failed\n", 17), NULL);
	b -> number = --count;
	b -> next = NULL;
	while (--count >= 0)
	{
		b -> next = b;
		b -> number = count;
		b -> prev = malloc(sizeof(t_list));
		if (!b -> prev)
			return (write(1, "\n\n\nmalloc failed\n", 17), NULL);
		b = b -> prev;
	}
}
























