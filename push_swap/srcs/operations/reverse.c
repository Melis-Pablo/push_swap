/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 02:13:17 by pmelis            #+#    #+#             */
/*   Updated: 2023/10/14 00:55:13 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
reverse:		rotates the stack so the bottom node becomes the top node

Parameters:		t_stack **stack

Return:			void

How it works:	1. Initialize last node holder
				2. If Stack or Nodes empty
					3. Return
				4. set holder to last node
				5. set last_node->prev->next = null
				6. set last_node->next = stack
				7. set last_node->prev = null
				8. set stack to last_node
				9. set last_node->next->prev = last node
*/
static void	reverse(t_stack **stack)
{
	t_stack	*last_node;

	if (stack == NULL || *stack == NULL)
		return ;
	last_node = ft_stacklast(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
*/
void	rra(t_stack **a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

/*
rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.
*/
void	rrb(t_stack **b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

//	rrr : rra and rrb at the same time.
void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}
