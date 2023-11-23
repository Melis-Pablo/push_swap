/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:52:36 by pmelis            #+#    #+#             */
/*   Updated: 2023/10/12 23:20:07 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
main:			Push_swap program, orders a stack of values and prints its steps.

Parameters:		int argc
				int argv (list of arguments, non-repeating numbers)

Return:			int

How it works:	1. Initialize t_stack *a
				2. Initialize t_stack *b
				3. set a = null
				4. set b = null
				5. if argc is 1 or 2 but second is empty (no arguments given)
					6. return 1
				7. else if 2 arguments given
					8. set argv to ft_split(argv) (create fake argv by separating numbers)
				9. initialize stacks (creating linked list with correct values & error check)
				10. If not is_sorted
					11. if stack has 2 values
						12. swap them
					13. else if stack has 3 values
						14. do small sort
					15. else if has more values
						16. use big sort
				17. free stacks from memory
*/

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_stack_init(&a, argv + 1, argc == 2);
	if (!is_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a);
		else if (ft_stack_len(a) == 3)
			sort_3(&a);
		else
			big_sort(&a, &b);
	}
	free_stack(&a);
}
