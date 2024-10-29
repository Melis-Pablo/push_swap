/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 02:13:15 by pmelis            #+#    #+#             */
/*   Updated: 2023/10/14 01:06:33 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
rotate:			rotates stack so top node becomes last node.

Parameters: 	t_stack **stack

Return:			void

How it works:	1. Initialize last_node
				2. if stack or nodes empty
					3. return
				4. set last_node
				5. set last_node->next = top of stack
				6. set *stack to next in stack
				7. set stack->prev = null
				8. set last_node->next->prev = last_node
				9. set last_node->next->next = null
*/
static void	rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (stack == NULL || *stack == NULL)
		return ;
	last_node = ft_stacklast(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

/*
a (rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one.
*/
void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

/*
rb (rotate b): Shift up all elements of stack b by 1.
	The first element becomes the last one.
*/
void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

//	rr : ra and rb at the same time.
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
