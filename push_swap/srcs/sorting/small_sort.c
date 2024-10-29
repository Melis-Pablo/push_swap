/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:57:07 by pmelis            #+#    #+#             */
/*   Updated: 2023/10/11 02:18:57 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
find_highest:	finds highest value node in stack.

Parameters:		t_stack *stack

Return:			t_stack *highest_node

How it works:	1. Initialize int highest
				2. Initialize t_stack *highest_node
				3. If stack empty
					4. return Null
				5. set highest to MIN_INT as initial value to compare
				6. while stack still going
					7. if stack value > highest
						8. set that node value as highest
						9. set that node as highest_node
					10. set stack to next
				11. Return highest_node
*/

static t_stack	*find_highest(t_stack *stack)
{
	int		highest;
	t_stack	*highest_node;

	if (stack == NULL)
		return (NULL);
	highest = -2147483648;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

/*
sort_3:			sorts stack of 3 values.

Parameters:		t_stack **a

Return:			void

How it works:	1. Initialize t_stack *highest
				2. set highest to find_highest(*a)
				3. If first one highest
					4. bottom it out with rotating stack
				5. else if next (2nd) is highest
					6. bottom it out with reverse rotating stack
				7. if 1st > 2nd
					8. swap them
*/

void	sort_3(t_stack **a)
{
	t_stack	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		ra(a);
	else if ((*a)->next == highest)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

/*
sort_5:			sorts stack with 5 values --> moves to b in order until 3 left

Parameters:		t_stack **a
				t_stack **b

Return:			void

How it works:	1. While length of stack a is more than 3
					2. initialize stacks
					3. rotate or rev_rotate until smallest at top
					4. push to b
*/

void	sort_5(t_stack **a, t_stack **b)
{
	while (ft_stack_len(*a) > 3)
	{
		initializer(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(a, b);
	}
}

/*
return_cheapest:	returns cheapest node in stack

Parameters:			t_stack *stack

Return:				t_stack *stack

How it works:		1. if stack empty
						2. return null
					3. while stack still going
						4. if stack node is cheapest
							5. return stack current node
						6. set stack to next
					7. return null
*/

t_stack	*return_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
