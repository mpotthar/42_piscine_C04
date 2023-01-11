/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:12:48 by mpotthar          #+#    #+#             */
/*   Updated: 2022/08/10 12:49:55 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	numlen;
	int	num;

	i = 0;
	minus = 0;
	numlen = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (ft_isnum(str[i]) == 1)
		num = (num * 10) + (str[i++] - '0');
	if (minus % 2 == 1)
		num *= -1;
	return (num);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;

// 	str = "      +--+-2147483648ThisIsTheMinInt.";
// 	printf("%d", ft_atoi(str));
// }