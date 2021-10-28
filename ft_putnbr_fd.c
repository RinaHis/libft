/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarkas <nfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 04:16:39 by nfarkas           #+#    #+#             */
/*   Updated: 2021/10/15 04:29:30 by nfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	i;
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr != 0)
	{
		if (nbr / 10 > 0)
			ft_putnbr_fd(nbr / 10, fd);
		i = nbr % 10 + 48;
		write(fd, &i, 1);
	}
	if (n == 0)
		write(fd, "0", 1);
}
