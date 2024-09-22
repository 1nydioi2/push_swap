#include "push_swap.h"

void	prin(t_list *lst, char *str)
{
	while (lst && lst -> status)
	{
		printf("%s", str);
		printf(" index n°%d ; pos n°%d ; content = %d\n", lst -> index, lst -> pos, lst -> content);
		lst = lst -> next;
	}
	write(1, "\n", 1);
}
