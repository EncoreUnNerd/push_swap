/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:31:03 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/06 13:33:23 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				cost;
	struct s_stack	*aim;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

t_stack	*reverse_rotate(t_stack *stack, int l);
t_stack	*rotate(t_stack *stack, int l);
t_stack	*swap(t_stack *stack, int l);
t_stack	*add_back(t_stack *stack, int data);
t_stack	*bring_to_bottom(t_stack *position, t_stack *stack, int l);
t_stack	*bring_top(t_stack *position, t_stack *stack, int l);
t_stack	*to_push_l(t_stack *stack_s, t_stack *stack_r);
t_stack	*to_push_b(t_stack *stack_s, t_stack *stack_r);
t_stack	*find_nearest_l(t_stack *position, t_stack *stack);
t_stack	*find_nearest_b(t_stack *position, t_stack *stack);
t_stack	*biggest_in_stack(t_stack *stack);
t_stack	*smallest_in_stack(t_stack *stack);
t_stack	*swap_r(t_stack *stack);
t_stack	*reverse_rotate_r(t_stack *stack);
t_stack	*rotate_r(t_stack *stack);
void	swap_swap(t_stack **a, t_stack **b);
void	rotate_rotate(t_stack **a, t_stack **b);
void	reverse_rotate_rotate(t_stack **a, t_stack **b);
void	push(t_stack **sender, t_stack **receiver, int l);
void	free_all_nodes(t_stack *stack);
void	move_top_separely(t_stack **s1, t_stack **s2, t_stack *p, int e[2]);
int		check_args_validity(int number, char **value);
int		stack_len(t_stack *a);
int		where_in_stack(t_stack *position, t_stack *stack);
int		len_to_top(t_stack *position, t_stack *stack);
int		is_sorted(t_stack *stack);
int		down_or_up(t_stack *position, t_stack *stack);
int		check_if_on_top(t_stack *position, t_stack *stack);

#endif