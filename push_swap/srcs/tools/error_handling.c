/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:16:57 by pmelis            #+#    #+#             */
/*   Updated: 2023/10/10 19:54:08 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
syntax_error:	checks for syntax errors.

Parameters:		char *str_num

Return:			int (1 or 0 as boolean)

How it Works:	1. If str_num is not '+' or '-' or not a digit
					2. Return 1
				3. If str_num is '+' or '-' and next char is not a number
					4. Return 1
				5. While *str still going
					6. if is not a digit
						7. Return 1
				8. Return 0 if non of the cases apply
*/

int	syntax_error(char *str_num)
{
	if (!(*str_num == '+' || *str_num == '-'
			|| (*str_num >= '0' && *str_num <= '9')))
		return (1);
	if ((*str_num == '+' || *str_num == '-')
		&& !(str_num[1] >= '0' && str_num[1] <= '9'))
		return (1);
	while (*++str_num)
	{
		if (!(*str_num >= '0' && *str_num <= '9'))
			return (1);
	}
	return (0);
}

/*
repetition_error:	Checks for repetition in stack.

Parameters:			t_stack *a
					int num

Return:				int (used as boolean)

How it works:		1. If a is null or empty
						2. Return 0 (false)
					3. While a still going
						4. if a->value is = to current num in stack
							5. Return 1 (true)
						6. a = next in stack
					7. Return 0 (false)
*/

int	repetition_error(t_stack *a, int num)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}

/*
free_matrix:	frees the memory allocated for argv.

Parameters:		char **argv

Return:			void

How it works:	1. Initialize i
				2. Set i to -1
				3. If argv Null
					4. Return
				5. While argv is going
					6. free argv and increment 
				7. free argv - 1 (placeholder for fake argv)
*/

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

/*
free_stack:		Frees the stack of parameters.

Prameters:		t_stack **stack

Return:			void

How it works:	1. Initialize tmp t_stack
				2. Initialize current t_stack
				3. if stack given null
					4. return
				5. set current to stack
				6. while current still going
					7. set tmp to next node
					8. free current
					9. set current to tmp
				10. set *stack = null
*/

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/*
free_error:		frees corresponding stack and writes to std error.

Parameters:		t_stack **a
				char **argv
				int flag_argc_2 (used as boolean to determine if fakeargv)

Return:			void

How it works:	1. free_stack
				2. if fakeargv
					3. free_matrix
				4. write to std error
				5. exit function
*/

void	free_error(t_stack **a, char **argv, int flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit (1);
}
