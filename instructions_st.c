#include "push_swap.h"

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}

void	rrr(t_list **a, t_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
