/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:56:03 by schennal          #+#    #+#             */
/*   Updated: 2023/05/30 18:38:30 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_largest_int(t_stack *stack, int max)
{
	int	i;
	int	next_max;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	next_max = INT_MIN;
	while (i < stack->size)
	{
		if (stack->stack[i] > next_max && stack->stack[i] < max)
			next_max = stack->stack[i];
		i++;
	}
	return (next_max);
}

int	find_index(t_stack *stack, int number)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == number)
			return (i);
		i++;
	}
	return (-1);
}

int	largest_number(t_stack *stack)
{
	int	i;
	int	max;

	if (!stack || !stack->stack)
		return (0);
	i = 0;
	max = stack->stack[0];
	while (i < stack->size)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

int	is_integer(char *str)
{
	int		len;
	char	sign;

	sign = '+';
	len = ft_strlen(str);
	if (str[0] == '-')
	{
		sign = '-';
		len--;
	}
	if (str[0] == '+')
	{
		sign = 'p';
		len--;
	}
	if (len > 10)
		return (0);
	else if (len < 10)
		return (1);
	else
		return (check_limits(str, sign));
}
