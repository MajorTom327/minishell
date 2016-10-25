/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 00:11:09 by vthomas           #+#    #+#             */
/*   Updated: 2016/10/25 02:48:07 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <signal.h>

int	set_env(t_shenv *e)
{
	set_prompt("minishell>", e);
	e->cont = 1;
	//signal(0x0C, sigint_handler);
}
