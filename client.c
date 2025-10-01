/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meesen <meesen@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:13:17 by meesen            #+#    #+#             */
/*   Updated: 2025/10/01 16:34:00 by meesen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "minitalk.h"

int ft_atoi(const char *str)
{
    int i = 0;
    int res = 0;
    int sign = 1;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sign);
}

void send_bit(pid_t pid, char c)
{
    int i = 7;

    while (i >= 0)
    {
        if ((c >> i) & 1)
        {
            if (kill(pid, SIGUSR2) == -1)
            {
                perror("Error sending SIGUSR2");
                exit(1);
            }
        }
        else
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                perror("Error sending SIGUSR1");
                exit(1);
            }
        }
        usleep(150);
        i--;
    }
}

int main(int ac, char **av)
{
    pid_t pid;
    int i;

    if (ac != 3)
    {
        write(1, "Usage: ./client <PID> <message>\n", 32);
        return (1);
    }

    pid = (pid_t)ft_atoi(av[1]);
    if (pid <= 0)
    {
        write(1, "Error: invalid PID\n", 19);
        return (1);
    }

    if (kill(pid, 0) == -1)
    {
        perror("Error: server not running or PID invalid");
        return (1);
    }

    i = 0;
    while (av[2][i])
    {
        send_bit(pid, av[2][i]);
        i++;
    }
    return (0);
}
