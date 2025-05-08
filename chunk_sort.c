/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:59:15 by schennal          #+#    #+#             */
/*   Updated: 2023/05/30 19:03:35 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smallest_top(t_stack *stack, char c, int number)
{
	int	index;

	index = find_index(stack, number);
	if (index == -1)
		return ;
	if (index <= stack->size / 2)
	{
		while (stack->stack[0] != number)
			do_rotate(stack, c);
	}
	else
	{
		while (stack->stack[0] != number)
			do_reverse_rotate(stack, c);
	}
}

int	find_index_smallest(t_stack *stack, int min)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] <= min)
			break ;
		i++;
	}
	return (i);
}

int	find_next_smallest(t_stack *stack, int min)
{
	int	i;
	int	next_min;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	next_min = INT_MAX;
	while (i < stack->size)
	{
		if (stack->stack[i] > min && stack->stack[i] < next_min)
			next_min = stack->stack[i];
		i++;
	}
	return (next_min);
}

void	chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	index;
	int	min;
	int	t;

	while (stack_a->size)
	{
		t = 0;
		min = find_smallest(stack_a);
		while (t++ < chunk_size)
		{
			min = find_next_smallest(stack_a, min);
			if (t == chunk_size / 2)
				stack_a->middle = min;
		}
		t = 0;
		while (t++ < chunk_size)
		{
			index = find_index_smallest(stack_a, min);
			smallest_top(stack_a, 'a', stack_a->stack[index]);
			do_pb(stack_a, stack_b);
			if (stack_b->stack[0] < stack_a->middle)
				do_rotate(stack_b, 'b');
		}
	}
	push_b_to_a(stack_a, stack_b);
}
