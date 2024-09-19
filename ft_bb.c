#include "push_swap.h"

int	alr_sorted(t_list *a)
{
	while (a -> next)
	{
		if (a -> index > a -> next -> index)
			return (0);
		a = a -> next;
	}
	return (1);
}

void	three(t_list **a)
{
	if ((*a) -> index == 1 && (*a) -> next -> index == 0)
		swap(a, 1);
	else if ((*a) -> index == 1 && (*a) -> next -> index == 2)
		rev_rotate(a, 1);
	else if ((*a) -> index == 2 && (*a) -> next -> index == 0)
		rotate(a, 1);
	else if ((*a) -> index == 2 && (*a) -> next -> index == 1)
	{
		swap(a, 1);
		rev_rotate(a, 1);
	}
	else if ((*a) -> index == 0 && (*a) -> next -> index == 2)
	{
		rev_rotate(a, 1);
		swap(a, 1);
	}
}

void	four(t_list **a, t_list **b)
{
	if ((*a) -> next -> index == 0)
		swap (a, 1);
	else if ((*a) -> next -> next -> index == 0)
	{
		rotate(a, 1);
		rotate(a, 1);
	}
	else if ((*a) -> next -> next -> next -> index == 0)
		rev_rotate(a, 1);
	push(a, b, 1);
	three(a);
	push(b, a, 2);
}

void	five(t_list **a, t_list **b)
{
	if ((*a) -> next -> index == 0)
		swap (a, 1);
	else if ((*a) -> next -> next -> index == 0)
	{
		rotate(a, 1);
		rotate(a, 1);
	}
	else if ((*a) -> next -> next -> next -> index == 0)
	{
		rev_rotate(a, 1);
		rev_rotate(a, 1);
	}
	else if ((*a) -> next -> next -> next -> next -> index == 0)
		rev_rotate(a, 1);
	push(a, b, 1);
	four(a, b);
	push(b, a, 2);
}
