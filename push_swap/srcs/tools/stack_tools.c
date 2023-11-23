/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 00:51:15 by pmelis            #+#    #+#             */
/*   Updated: 2023/10/11 01:27:34 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
ft_stacklast:	finds the last node in a stack.

Parameters:		t_stack *stack

Return:			t_stack *stack

How it works:	1. if stack null
					2. return null
				3. while stack has next
					4. set stack to next
				5. return stack
*/

t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack -> next)
		stack = stack->next;
	return (stack);
}

/*
add_node:		adds node to end of stack.

Parameters:		t_stack **stack
				int n

Return:			void

How it works:	1. Initializes t_stack *node
				2. Initializes t_stack *last_node
				3. If stack null
					4. Return
				5. allocate memory for node sizeof t_stack
				6. allocation check
					7. return if failed
				8. set node->next to null
				9. set node->value to n
				10. if stack empty
					11. set stack to node
					12. set node->prev to null
				13. else if stack not empty
					14. last_node = ft_stacklast(stack)
					15. last_node->next = node
					16. node->prev = last_node
*/

void	add_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = n;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_stacklast(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

/*
ft_stack_len:	returns length of stack.

Parameters:		t_stack *stack

Return:			int len

How it works:	1. Initialize int len
				2. If stack empty
					3. return 0
				4. set len to 0
				5. while stack still going
					6. increase len
					7. set stack to next
				8. return len
*/

int	ft_stack_len(t_stack *stack)
{
	int	len;

	if (stack == NULL)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

/*
is_sorted:		checks if stack is already sorted

Parameters:		t_stack *stack

Return:			int (as boolean)

How it works:	1. If stack empty
					2. return 0
				3. while stack has next
					4. if value bigger than next value
						5. return 0
					6. set stack to next
				7. return 1
*/

int	is_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
find_smallest:	finds smallest value node in stack.

Parameters:		t_stack *stack

Return:			t_stack *smallest_node

How it works:	1. Initialize long smallest
				2. Initialize t_stack *smallest_node
				3. If stack empty
					4. return Null
				5. set smallest to MAX_INT as initial value to compare
				6. while stack still going
					7. if stack value < smallest
						8. set that node value as smallest
						9. set that node as smallest_node
					10. set stack to next
				11. Return smallest_node
*/

t_stack	*find_smallest(t_stack *stack)
{
	long	smallest;
	t_stack	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = 2147483647;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}
