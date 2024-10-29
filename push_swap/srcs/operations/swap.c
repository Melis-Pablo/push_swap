/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 02:13:00 by pmelis            #+#    #+#             */
/*   Updated: 2023/10/16 23:38:12 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
swap:			swaps top 2 elements of stack.

Parameters:		t_stack **stack

Return:			void

How it works:	1. If stack or nodes empty
					2. return
				3. stack = stack next
				4. stack->prev->prev = stack
				5. stack->prev->next = stack->next
				6. if stack has next
					7. stack next->prev = stack->prev
				8. stack->next = stack->prev
				9. stack->prev = null
*/
static void	swap(t_stack **stack)
{
	if (stack == NULL || *stack == NULL)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
*/
void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

/*
sb (swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.
*/
void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

//	ss : sa and sb at the same time.
void	ss(t_stack **a, t_stack	**b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
