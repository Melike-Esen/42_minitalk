#include "minitalk.h"

int	ft_atoi(const char *str)
{
    int i;
    int res;
    int sign;

    i = 0;
    res = 0;
    sign = 1;

    while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
        i++;
    if(str[i] == '-' || str[i] == '+')
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
void	send_bit(pid_t pid, char c)
{
    int i;
    
    i = 7;
    while ( i >= 0)
    {
        if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(150);
		i--;
	}
 }

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac != 3)
	{
		ft_putstr("Usage: ./client <PID> <message>\n");
		return (1);
	}
	pid = (pid_t)ft_atoi(av[1]); 
	i = 0;
	while (av[2][i])
	{
		send_bit(pid, av[2][i]);
		i++;
	}
	return (0);
} 


