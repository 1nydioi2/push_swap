#include "push_swap.h"

void	indexator(t_list *lst, int *tab, int count)
{
	t_list *chti;
	int	index;

	index = 0;
	while (index < count)
	{
		chti = lst;
		while (lst -> next)
		{
			if (chti -> content > lst -> content && !chtitator(chti))
				chti = lst;
			lst = lst -> next;
		}
		chti -> index = index++;
	}
}

void	addnewf(t_list **lst, int content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return; 
	new -> content = content;
	new -> next = *lst;
	new -> status = 1;
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
	head -> status = 1;
	while (--count >= 0)
		addnewf(&head, tab[count]);
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
	b -> next = NULL;
	b -> status = 0;
	while (--count >= 0)
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
























