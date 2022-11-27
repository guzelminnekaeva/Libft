/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhizdahr <zhizdahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:30:03 by zhizdahr          #+#    #+#             */
/*   Updated: 2021/10/15 16:48:56 by zhizdahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	sravn(char *dec, char str)
{
	int	j;

	j = 0;
	while (dec[j] != 0)
	{
		if (str == dec[j])
			return (1);
		j++;
	}
	return (0);
}

static int	zikl(const char	*str, int i, int m, int ch)
{
	while (ch == 1)
	{
		ch = sravn(" \t\n\v\f\r", str[i]);
		i++;
	}
	i--;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			m++;
		i++;
	}
	if (str[i] > 47 && str[i] < 58)
	{
		ch = str[i] - '0';
		i++;
		while (str[i] > 47 && str[i] < 58)
		{
			ch = ch * 10 + str[i] - '0';
			i++;
		}
		if (m % 2 == 1)
			ch *= -1;
	}
	return (ch);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	m;
	int	ch;

	m = 0;
	i = 0;
	ch = 1;
	ch = zikl(str, i, m, ch);
	return (ch);
}
