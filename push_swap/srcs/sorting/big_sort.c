/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:53 by pmelis            #+#    #+#             */
/*   Updated: 2023/10/14 00:30:04 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
double_rotate:	rotates both stacks until cheapest node or target node is at top
				and sets their new positions.

Parameters:		t_stack **a
				t_stack **b
				t_stack *cheapest

Return:			void

How it works:	1. While a is not cheapest target, and b is not cheapest
					2. rotate both stacks
				3. sets new a position
				4. sets new b position
*/

static void	double_rotate(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b);
	set_position(*a);
	set_position(*b);
}

/*
double_reverse_rotate:	reverse rotates both stacks until cheapest node or
						target node is at top and sets their new positions.

Parameters:				t_stack **a
						t_stack **b
						t_stack *cheapest

Return:					void

How it works:			1. While a is not cheapest target, and b is not cheapest
							2. reverse rotate both stacks
						3. sets new a position
						4. sets new b position
*/

static void	double_reverse_rotate(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b);
	set_position(*a);
	set_position(*b);
}

/*
finish_rotation:	sets cheapest node or target node to top of stack.

Parameters:			t_stack **stack
					t_stack *top_node
					char name

Return:				void

How it works:		1. While node is not at top of stack
						2. if stack is a
							3. if above median
								4. rotate a
							5. else
								6. reverse rotate a
						7. else if stack is b 
							8. if above median
								9. rotate b
							10. else
								11. reverse rotate b
*/

void	finish_rotation(t_stack **stack, t_stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

/*
move_nodes:		makes the moves to push the correct node back to its spot on a

Parameters:		t_stack **a
				t_stack **b

Return:			void

How it works:	1. Initialize cheapest holder
				2. set cheapest by return_cheapest
				3. if cheapest and the target node are above median 
					4. double rotate
				5. else if both below median
					6. double reverse rotate
				7. finish b rotation
				8. finish a rotation
				9. push b to a
*/

static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		double_rotate(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		double_reverse_rotate(a, b, cheapest);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target_node, 'a');
	pa(b, a);
}

/*
big_sort:		sorts stack of more than 3 nodes/numbers

Parameters:		t_stack *a
				t_stack *b

Return:			void

How it works:	1. Initialize smallest node
				2. Initialize int a_len
				3. set a len
				4. if a len = 5
					5. sort_5
				6. else
					7. while a_len-- > 3
						8. push b
				9. sort_3 a
				10. while b still going
					11. Initializer
					12. Move nodes
				13. set position a
				14. set smallest node
				15. if smallest above median
					16. while a is not smallest node
						17. rotate a
				18. else
					19. while a is not smallest node
						20. reverse rotate a
*/

void	big_sort(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		a_len;

	a_len = ft_stack_len(*a);
	if (a_len == 5)
		sort_5(a, b);
	else
	{
		while (a_len-- > 3)
			pb(a, b);
	}
	sort_3(a);
	while (*b)
	{
		initializer(*a, *b);
		move_nodes(a, b);
	}
	set_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
