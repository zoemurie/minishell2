/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmurie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:53:58 by zmurie            #+#    #+#             */
/*   Updated: 2025/04/17 09:54:03 by zmurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minishell.h"

int	ft_envsize(t_env *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

char	**convert_list_to_tab_str(t_env *env)
{
	char	**tab_str;
	t_env	*tmp_env;
	int		i;
	tab_str = malloc(sizeof(char *) * (ft_envsize(env) + 1));
	if (!tab_str)
		return (NULL);
	tmp_env = env;
	i = 0;
	if (tmp_env->value)
	{
		tab_str[i] = tmp_env->value;
		i++;
	}
	while (tmp_env->next)
	{
		tmp_env = tmp_env->next;
		tab_str[i] = tmp_env->value;
		i++;
	}
	tab_str[i] = NULL;
	return (tab_str);
}
