#include "push_swap.h"

void	prin(t_list *lst, char *str)
{
	while (lst -> next)
	{
		printf("%s", str);
		printf(" n°%d = %d\n", lst -> index, lst -> content);
		lst = lst -> next;
	}
		printf("%s", str);
		printf(" n°%d = %d\n\n", lst -> index, lst -> content);
}
