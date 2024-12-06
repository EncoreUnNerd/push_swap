/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <mhenin@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:32:49 by mhenin            #+#    #+#             */
/*   Updated: 2024/12/06 13:35:52 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top_separely(t_stack **s1, t_stack **s2, t_stack *p, int e[2])
{
	*s1 = bring_top(p, *s1, e[0]);
	*s2 = bring_top(p->aim, *s2, e[1]);
}
