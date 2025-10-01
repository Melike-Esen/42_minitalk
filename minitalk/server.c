/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meesen <meesen@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:36:50 by meesen            #+#    #+#             */
/*   Updated: 2025/10/01 15:54:00 by meesen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int signum)
{
    static unsigned char c = 0;
    static int bit = 0;

    if (signum == SIGUSR2)       // 1 bit
        c |= (1 << (7 - bit));
    // SIGUSR1 = 0 bit → hiçbir şey yapma

    bit++;
    if (bit == 8)
    {
        ft_putchar(c);
        bit = 0;
        c = 0;
    }
}

int	main(void)
{
	struct sigaction sa;

	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');

	sa.sa_handler = &signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause(); // sinyal gelene kadar bekle
	return (0);
}