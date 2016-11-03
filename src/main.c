/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 22:07:37 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/03 05:08:59 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

int	main(int ac, char **av, char **env)
{
	t_sh *sh;
	dbg_var_int("main", "hash for pwd", hash("pwd"), 0);
	dbg_var_int("main", "hash for echo", hash("echo"), 0);
	dbg_var_int("main", "hash for cd", hash("cd"), 0);
	sh = init(env);
	terminal(sh);
	loop(sh);
//	if (sh == NULL)
//		dbg_info("main", "sh is null !", 0);
//	if (sh->cmd == NULL)
//		dbg_info("main", "sh->cmd is null !", 0);
//	if (tree_search(sh->cmd, "pwd") == NULL)
//		dbg_info("main", "search for pwd is null !", 0);
//	if (tree_search(sh->cmd, "echo") == NULL)
//		dbg_info("main", "search for echo is null !", 0);
//	dbg_var_str("main", "pwd in tree", ((t_cmd *)(tree_search(sh->cmd, "pwd"))->value)->name, 0);
//	dbg_var_str("main", "env in tree", ((t_cmd *)(tree_search(sh->cmd, "env"))->value)->name, 0);
//	dbg_var_str("main", "cd in tree", ((t_cmd *)(tree_search(sh->cmd, "cd"))->value)->name, 0);
//	dbg_var_str("main", "echo in tree", ((t_cmd *)(tree_search(sh->cmd, "echo"))->value)->name, 0);
//	dbg_var_str("main", "path", (env_search(sh->env, "PATH"))->key, 0);
	return (0);
}
