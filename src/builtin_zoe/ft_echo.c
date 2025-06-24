/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmurie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:42:30 by zmurie            #+#    #+#             */
/*   Updated: 2025/03/14 11:42:32 by zmurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minishell.h"

static bool	check_new_line(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i] == '-')
	{
		i++;
		while (str[i] && str[i] == 'n')
			i++;
		if (i == (int)ft_strlen(str))
			return (true);
	}
	return (false);
}

int	ft_echo(t_cmd *cmd)
{
	int		i;
	int		nbr_arg;
	bool	new_line;

	nbr_arg = 0;
	new_line = false;
	while (cmd->args[nbr_arg + 1])
		nbr_arg++;
	i = 0;
	while (cmd->args[++i] && check_new_line(cmd->args[i]))
			new_line = true;
	while (cmd->args[i])
	{
		write(1, cmd->args[i], ft_strlen(cmd->args[i]));
		if (i != nbr_arg)
			write(1, " ", 1);
		i++;
	}
	if (!new_line)
		write(1, "\n", 1);
	return (0);
}
// int	main(int argc, char **argv)
// {

// 	(void)argc;
// 	ft_echo(argv);
// 	return (0);
// }