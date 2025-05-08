/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:11:20 by schennal          #+#    #+#             */
/*   Updated: 2023/05/30 18:38:45 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_sign(char c)
{
	return (c == '+' || c == '-');
}

static int	is_only_spaces(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_limits(char *str, char sign)
{
	if (sign == '+' && ft_strcmp(str, "2147483647") > 0)
		return (0);
	else if (sign == 'p' && ft_strcmp(str + 1, "2147483647") > 0)
		return (0);
	else if (sign == '-' && ft_strcmp(str + 1, "2147483647") > 0)
		return (0);
	else
		return (1);
}

/*
will output 0 if not a digit
will output 0 if not integer
will output 0 if not duplicate
*/

static void	ft_are_args_valid(char *argv)
{
	int	i;
	int	consecutive_signs;

	i = 0;
	consecutive_signs = 1;
	while (argv[i])
	{
		if (ft_is_sign(argv[i]) && argv[i - 1] != ' ' && i != 0)
			ft_error(NULL, NULL, NULL);
		if (ft_is_sign(argv[i]) && !ft_isdigit(argv[i + 1]))
			ft_error(NULL, NULL, NULL);
		if (ft_isdigit(argv[i]) || argv[i] == ' ')
			consecutive_signs = 0;
		if (ft_is_sign(argv[i]) && consecutive_signs < 2)
			consecutive_signs++;
		if (!ft_isdigit(argv[i]) && !ft_is_sign(argv[i]) && argv[i] != ' ')
			ft_error(NULL, NULL, NULL);
		i++;
	}
}

void	check_ip(int ac, char**av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			ft_error(NULL, NULL, NULL);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		if (is_only_spaces(av[i]))
			ft_error(NULL, NULL, NULL);
		ft_are_args_valid(av[i]);
		i++;
	}
}
