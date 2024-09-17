#include "push_swap.h"

void	prin(t_list *lst, char *str)
{
	while (lst)
	{
		printf("%s", str);
		printf(" n°%d = %d\n", lst -> index, lst -> content);
		lst = lst -> next;
	}
	write(1, "\n", 1);
}
