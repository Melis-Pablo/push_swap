/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:52:55 by pmelis            #+#    #+#             */
/*   Updated: 2023/10/16 23:42:16 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> //read - write
# include <stdlib.h> //malloc - free - exit

/////////////////////Struct: Linked List/////////////////////////
typedef struct s_stack
{
	int					value;
	int					current_position;
	int					push_price;
	int					above_median;
	int					cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}				t_stack;

///////////////////////////Operations////////////////////////////
//static void		push(t_stack **src, t_stack **dst);
void			pa(t_stack **b, t_stack **a);
void			pb(t_stack **a, t_stack **b);

//static void		swap(t_stack **stack);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack	**b);

//static void		rotate(t_stack **stack);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);

//static void		reverse(t_stack **stack);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);

///////////////////////////Tools/////////////////////////////////
/////-stack_tools-/////
t_stack			*ft_stacklast(t_stack *stack);
void			add_node(t_stack **stack, int n);
int				ft_stack_len(t_stack *stack);
int				is_sorted(t_stack *stack);
t_stack			*find_smallest(t_stack *stack);
/////-stack_init-/////
//static long		ft_atol(const char *str);
void			ft_stack_init(t_stack **a, char **argv, int flag_argc_2);
/////-ft_split-/////
//static int		count_words(char *str, char separator);
//static char		*get_word(char *str, char separator);
char			**ft_split(char *str, char separator);
/////-error_handling-/////
int				syntax_error(char *str_num);
int				repetition_error(t_stack *a, int num);
void			free_matrix(char **argv);
void			free_stack(t_stack **stack);
void			free_error(t_stack **a, char **argv, int flag_argc_2);
/////-big_sort_tools-/////
//static void		set_target(t_stack *a, t_stack *b);
void			set_price(t_stack *a, t_stack *b);
void			set_position(t_stack *stack);
void			set_cheapest(t_stack *b);
void			initializer(t_stack *a, t_stack *b);
//////////////////////////Sorting////////////////////////////////
/////-small_sort-/////
//static t_stack	*find_highest(t_stack *stack);
void			sort_3(t_stack **a);
void			sort_5(t_stack **a, t_stack **b);
t_stack			*return_cheapest(t_stack *stack);
/////-big_sort-/////
//static void		double_rotate(t_stack **a, t_stack **b, t_stack *cheapest);
//static void		double_reverse_rotate
//			(t_stack **a, t_stack **b, t_stack *cheapest);
void			finish_rotation(t_stack **stack, t_stack *top_node, char name);
//static void		move_nodes(t_stack **a, t_stack **b);
void			big_sort(t_stack **a, t_stack **b);

#endif
