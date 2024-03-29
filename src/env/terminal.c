/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 04:52:18 by vthomas           #+#    #+#             */
/*   Updated: 2016/11/08 09:12:14 by vthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <termios.h>

void	terminal(t_sh *sh)
{
	struct termios t;

	tcgetattr(0, &t);
	t.c_lflag &= ECHOKE | ECHO;
	t.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &t);
	dbg_info("terminal", "Terminal setting done.", 1);
}
