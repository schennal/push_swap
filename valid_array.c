/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:28:21 by schennal          #+#    #+#             */
/*   Updated: 2023/05/19 00:34:49 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	correct_order(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
	}
}

static int	is_duplicates(int *array, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (array[i] == array[j] && j != i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	*valid_array(char	**string, t_stack *stack)
{
	long	n;
	int		i;
	int		j;
	int		*array;

	array = ft_calloc((stack->size + 1), sizeof(int));
	if (!array)
		return (NULL);
	i = stack->size - 1;
	j = 0;
	while (i >= 0)
	{
		n = ft_atoi(string[j++]);
		if (n > INT_MAX || n < INT_MIN)
			ft_error(string, stack, array);
		array[i--] = (int) n;
	}
	if (is_duplicates(array, stack))
		ft_error(string, stack, array);
	i = 0;
	while (string[i])
		free(string[i++]);
	free(string);
	correct_order(array, stack->size);
	return (array);
}
