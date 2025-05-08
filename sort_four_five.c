/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:54:34 by schennal          #+#    #+#             */
/*   Updated: 2023/05/23 22:01:46 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *stack)
{
	int	i;
	int	min;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	min = stack->stack[0];
	while (i < stack->size)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

void	smallest_to_top(t_stack *stack, char c)
{
	int	i;
	int	min;

	if (!stack || !stack->stack)
		return ;
	i = 0;
	min = find_smallest(stack);
	while (stack->stack[i] != min)
		i++;
	if (i <= stack->size / 2)
	{
		while (stack->stack[0] != min)
			do_rotate(stack, c);
	}
	else
	{
		while (stack->stack[0] != min)
			do_reverse_rotate(stack, c);
	}
}

void	sort_four_and_five(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size == 4)
	{
		smallest_to_top(stack_a, 'a');
		do_pb(stack_a, stack_b);
		if (!is_sorted(stack_a))
			sort_three(stack_a);
		do_pa(stack_a, stack_b);
	}
	else
	{
		smallest_to_top(stack_a, 'a');
		do_pb(stack_a, stack_b);
		smallest_to_top(stack_a, 'a');
		do_pb(stack_a, stack_b);
		if (!is_sorted(stack_a))
			sort_three(stack_a);
		do_pa(stack_a, stack_b);
		do_pa(stack_a, stack_b);
	}
}
