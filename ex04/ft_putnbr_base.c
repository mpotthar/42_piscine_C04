/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:35:18 by mpotthar          #+#    #+#             */
/*   Updated: 2022/08/10 15:37:51 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_baselen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

void	ft_output(long int l_nbr, char *base)
{
	int			arr[33];
	int			i;

	i = 0;
	while (l_nbr % ft_baselen(base) != l_nbr)
	{
		arr[i] = l_nbr % ft_baselen(base);
		l_nbr /= ft_baselen(base);
		i++;
	}
	arr[i++] = l_nbr % ft_baselen(base);
	while (i-- > 0)
		ft_putchar(base[arr[i]]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	l_nbr;

	l_nbr = nbr;
	if (ft_checkbase(base) == 1)
	{
		if (l_nbr < 0)
		{
			ft_putchar('-');
			l_nbr *= -1;
		}
		if (l_nbr == 0)
			ft_putchar(base[0]);
		if (l_nbr > 0)
		{
			ft_output(l_nbr, base);
		}
	}
}

// int	main(void)
// {
// 	int	nbr;
// 	char *base;

// 	base = "01";
// 	nbr = 2147483647;

// 	ft_putnbr_base(nbr, base);
// }