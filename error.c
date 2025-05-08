/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:08:26 by schennal          #+#    #+#             */
/*   Updated: 2023/05/27 14:54:18 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->stack);
	free(stack_a);
	free(stack_b->stack);
	free(stack_b);
}

void	ft_error(char **string, t_stack *stack, int *array)
{
	int	i;

	i = 0;
	if (array)
		free(array);
	if (string)
	{
		while (string[i])
			free(string[i++]);
		free(string);
	}
	if (stack)
	{
		free(stack->stack);
		free(stack);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
