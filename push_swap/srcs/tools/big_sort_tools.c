/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:45:58 by pmelis            #+#    #+#             */
/*   Updated: 2023/10/13 23:25:51 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
set_target:		sets target node for a node.

Parameters:		t_stack *a
				t_stack *b

Return:			void

How it works:	1. Initialize current_a node
				2. Initialize target_node
				3. Initialize long for best_match
				4. while b is not empty
					5. set best_match to max_long
					6. set curret_a to current node
					7. while current_a not empty
						8. if current_a > b value && current value < best_match
							9. best_match = current a value
							10. target node= current a
						11. current a = next a
					12. if best match == MAX_LONG
							13. target node = smallest
					14. else
						15. b target node = target_node
					16. b = next b
*/

static void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match;

	while (b)
	{
		best_match = 2147483647;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == 2147483647)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/*
set_price:		sets node price

Parameters:		t_stack *a
				t_stack *b

Return:			void

How it works:	1. Initialize a_len
				2. Initialize b_len
				3. set a_len
				4. set b_len
				5. while b still going
					6. set b push price to position number
					7. if b below median
						8. price = len - position
					9. if target above median
						10. price += b position
					11. else
						12. price += len - b position
					13. b = next b
*/

void	set_price(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	a_len = ft_stack_len(a);
	b_len = ft_stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = b_len - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += a_len - (b->target_node->current_position);
		b = b->next;
	}
}

/*
set_position:	sets node position.

Parameters:		t_stack *stack

Return:			void

How it works:	1. Initialize i
				2. Initialize midline
				3. set i to 0
				4. if stack null
					5. return
				6. midline = stack_len / 2
				7. while stack still going
					8. stack position = 1
					9. if i < midline
						10. stack above median
					11. if i > midline
						12. below median
					13. stack = next stack
					14. increment i
*/

void	set_position(t_stack *stack)
{
	int	i;
	int	midline;

	i = 0;
	if (stack == NULL)
		return ;
	midline = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= midline)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

/*
set_cheapest:	sets cheapest node

Parameters:		t_stack *b

Return:			void

How it works:	1. Initialize best_match_val
				2. Initialize best_match_node
				3. if b null
					4. return
				5. best val = int_max
				6. while b still going
					7. if b price < best val
						8. best val = b price
						9. best node = b
					10. b = next b
				11. set best match node to cheapest
*/

void	set_cheapest(t_stack *b)
{
	long	best_match_val;
	t_stack	*best_match_node;

	if (b == NULL)
		return ;
	best_match_val = 2147483647;
	while (b)
	{
		if (b->push_price < best_match_val)
		{
			best_match_val = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = 1;
}

/*
Initializer:	initialized the nodes with the correct values

Parameters:		t_stack *a
				t_stack *b

Return:			void

How it works:	1. sets a position
				2. sets b position
				3. sets target node
				4. sets price
				5. sets cheapest node
*/

void	initializer(t_stack *a, t_stack *b)
{
	set_position(a);
	set_position(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}
