/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginfranc <ginfranc@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:51:51 by ginfranc          #+#    #+#             */
/*   Updated: 2025/07/07 11:52:45 by ginfranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (nptr[i] && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		result *= 10;
		result = result + nptr[i] - 48;
		i++;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;	
	return (len);
}

