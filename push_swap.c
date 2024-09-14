/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:24:14 by nilamber          #+#    #+#             */
/*   Updated: 2024/09/14 17:27:16 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse(int c, char **v)
{
	int		i;
	int		j;

	i = 1;
	while (i < c)
	{
		j = 0;
		while (v[i][j])
		{
			if ((v[i][j] < '0' || v[i][j] > '9')
				&& (v[i][j] != 32 && (v[i][j] < 9 || v[i][j] > 13))
					&& (v[i][j] != '-' || (v[i][j] == '-' 
						&& (((v[i][j + 1] > '9' || v[i][j + 1] < '0')
							|| (j != 0 && (v[i][j - 1] != 32
								&& (v[i][j - 1] < 9 
									|| v[i][j - 1] > 13))))))))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int count(int c, char **v)
{
	int		i;
	int		j;
	int		res;

	i = 1;
	res = 0;
	while (i < c)
	{
		j = 0;
		while (v[i][j])
		{
			if (v[i][j] >= '0' && v[i][j] <= '9')
				res++;
			while (v[i][j] >= '0' && v[i][j] <= '9')
				j++;
			j += (v[i][j] != 0);
		}
		i++;
	}
	printf("\n(count)res = %d\n\n\n", res);
	return (res);
}

int	fatoi (char *str, int *status)
{
	int	res;
	int	sign;
	int	in;

	in = 0;
	res = 0;
	sign = 1;
	while (*str != '-' && (*str < '0' || *str > '9'))
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while ((*str && str) && (*str >= '0' && *str <= '9'))
	{
		if (in > 9 || ((in == 9 && res > 214748364) || (in == 9 && ((sign > 0 && *str > '7') || (sign < 0 && *str > '8')))))
		{
			*status = 1;
			return (res);
		}
		res *= 10;
		res += (*str - '0');
		in++;
		str++;
	}
	res *= sign;
	return (res);
}

int	*stock(char **v, int count, int c, int *status)
{
	int	i;
	int	k[2];
	int	*list;
	int 	res;
	
	list = malloc(sizeof(int) * count);
	i = 1;
	*k = 0;
	while (i < c)
	{
		k[1] = 0;
		res = fatoi(v[i], status);
		while (k[1] < *k)
		{
			if (res == list[k[1]++] || *status)
			{
				*status = 1;
				return (list);
			}
		}
		list[k[0]++] = res;
		while (*v[i] && (*v[i] != '-' || (*v[i] < '0' || *v[i] > '9')))
			v[i]++;
		if (!*v[i])
			i++;
	}
	return (list);
}

int	main(int c, char **v)
{
	int	*tab;
	int	*st;
	int status;
	int	couint;
	int	i = -1;
	t_list	*a;
	t_list	*b;

	status = 0;
	st = &status;
	if (c == 1)
		return (0);
	if (c < 2)
		return (write(1, "Error1a\n", 8));
	if (parse(c, v))
		return (write(1, "Error2p\n", 8));
	couint = count(c, v);
	tab = stock(v, couint, c, st);
	if (status == 1)
	{
		free(tab);
		return (write(1, "Error3d\n", 8));
	}
	while (++i < couint)
		printf("tab[%d] = %d\n", i, tab[i]);
	printf("\n\n");
	
	a = arrayst(couint, tab);
	while (a -> next)
	{
			printf("a n°%d (s = %d)= '%d'\n", a -> number, a -> status, a -> content);
		a = a -> next;
	}
	printf("a n°%d (s = %d)= '%d'\n", a -> number, a -> status, a -> content);
	while (a -> prev)
	{
		printf("a n°%d (s = %d)= '%d'\n", a -> number, a -> status, a -> content);
		a = a -> prev;
	}
	printf("a n°%d (s = %d)= '%d'\n\n\n", a -> number, a -> status, a -> content);
	
	b = blst(couint);
	while (b -> next)
	{
			printf("b n°%d (s = %d)= '%d'\n", b -> number, b -> status, b -> content);
		b = b -> next;
	}
	printf("b n°%d (s = %d)= '%d'\n", b -> number, b -> status, b -> content);
	while (b -> prev)
	{
		printf("b n°%d (s = %d)= '%d'\n", b -> number, b -> status, b -> content);
		b = b -> prev;
	}
	printf("b n°%d (s = %d)= '%d'\n", b -> number, b -> status, b -> content);

	free(tab);
	liberator(a);
	liberator(b);
}
