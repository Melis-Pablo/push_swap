/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 02:13:19 by pmelis            #+#    #+#             */
/*   Updated: 2023/10/14 00:42:16 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Push:		pushes the top node of a stack to the other stack

Parameters:	t_stack **src
			t_stack **dst

Return:		void

How it works:	1. Initializes to_push holder
				2. If src empty
					3. return
				4. set to_push = src
				5. src = next src
				6. if src has node
					7. set prev to null
				8. set to_push prev = null
				9. if dst null
					10. dst = to_push
					11. to_push next = null
				12. else
					13. to_push next = dst
					14. to_push prev = null
					15. dst = to_push
*/
static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*to_push;

	if (*src == NULL)
		return ;
	to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	to_push->prev = NULL;
	if (*dst == NULL)
	{
		*dst = to_push;
		to_push->next = NULL;
	}
	else
	{
		to_push->next = *dst;
		to_push->next->prev = to_push;
		*dst = to_push;
	}
}

/*
pa (push a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
*/
void	pa(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

/*
pb (push b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
*/
void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
