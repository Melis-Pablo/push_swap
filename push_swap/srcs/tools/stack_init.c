/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:32:23 by pmelis            #+#    #+#             */
/*   Updated: 2023/10/09 20:16:18 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
ft_atol:		takes char *str and returns the equivalent long number

Parameters:		char *str

Return:			long (num * isneg)

How it Works:	1. Initialize long num
				2. Initialize int isneg
				3. Initialize int i
				4. Set num to 0
				5. Set isneg to 1 (positive)
				6. Set i to 0
				7. While str still going and is white space
					8. i++
				9. if str[i] == +
					10. i++ (move along str)
				11. else if str[i] == -
					12. isneg *= -1
					13. i++ (move along str)
				14. While str = a digit
					15. set num to correct digit and power of 10 
					16. i++ (move along str)
				17. Return num * isneg
*/

static long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

/*
ft_stack_init:	Initializes Stack with correct values while error checking.

Parameters:		t_stack **a
				char **argv
				int flag_argc_2 (to check argv to free)

Return:			void

How it works:	1. Initialize long n
				2. Initialize int i
				3. set i to 0
				4. While argv[i] still going
					5. if syntax error found
						6. free and display error
					7. n = current number on array (ft_atol)
					8. if n is over max or under min
						9. free and display error
					10. if repetition error found
						11. free and display error
					12. add node to linked list
					13. i++ (move along array)
				14. if fake argv was used
					15. free matrix
*/

void	ft_stack_init(t_stack **a, char **argv, int flag_argc_2)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			free_error(a, argv, flag_argc_2);
		n = ft_atol(argv[i]);
		if (n > 2147483647 || n < -2147483648)
			free_error(a, argv, flag_argc_2);
		if (repetition_error(*a, (int)n))
			free_error(a, argv, flag_argc_2);
		add_node(a, (int)n);
		i++;
	}
	if (flag_argc_2)
		free_matrix(argv);
}
