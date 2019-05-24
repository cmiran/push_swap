#include "push_swap.h"

void	go_to_index(t_lst **a, int lo, int y)
{
	static int	n = 0;
	int			tmp;

	tmp = lo;
	lo -= n;
	n = tmp;
	while (lo--)
	{
		if (y)
		{
//			swap_me(a, 0);
			RA(a);
		}
		else
		{
//			swap_me(a, 0);
			RRA(a);
		}
	}
}

//	PRINT LIST
int		print_lst(t_lst **alst)
{
	t_lst	*start;

	start = *alst;
	while (*alst)
	{
		printf("%li", (*alst)->val);
		*alst = (*alst)->next;
		if (*alst)
			printf("  ");
	}
	*alst = start;
	if (*alst)
		printf("\nlen : %i\n", (*(*alst)->n));
	return (1);
}
