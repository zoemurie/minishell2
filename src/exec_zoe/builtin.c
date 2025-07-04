/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmurie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:03:23 by zmurie            #+#    #+#             */
/*   Updated: 2025/04/01 15:03:25 by zmurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minishell.h"

int	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "echo") \
		|| !ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "exit") \
		|| !ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "pwd") \
		||!ft_strcmp(cmd, "unset"))
		return (1);
	return (0);
}

int	do_builtin(t_shell_data *data, t_cmd *cmd)
{
	if (!ft_strcmp(cmd->args[0], "cd"))
		data->last_exit_status = ft_cd(cmd, data);
	else if (!ft_strcmp(cmd->args[0], "echo"))
		data->last_exit_status = ft_echo(cmd);
	else if (!ft_strcmp(cmd->args[0], "env"))
		data->last_exit_status = ft_env(data);
	else if (!ft_strcmp(cmd->args[0], "exit"))
		ft_exit(cmd, data);
	else if (!ft_strcmp(cmd->args[0], "export"))
		ft_export(cmd, data);
	else if (!ft_strcmp(cmd->args[0], "pwd"))
		data->last_exit_status = ft_pwd();
	else if (!ft_strcmp(cmd->args[0], "unset"))
		data->last_exit_status = ft_unset(cmd, data);
	return (data->last_exit_status);
}
