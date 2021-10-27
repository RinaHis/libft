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

//void	ft_putnbr_fd(int nb, int fd)
//{
//	unsigned int	nbr;
//
//	if (nb < 0)
//	{
//		ft_putchar_fd('-', fd);
//		nbr = (unsigned int)(nb * -1);
//	}
//	else
//		nbr = (unsigned int)nb;
//	if (nbr >= 10)
//		ft_putchar_fd(nbr / 10, fd);
//	ft_putchar_fd((char)(nbr % 10 + 48), fd);
//}
void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	nnbr;

	nnbr = n;
	if (nnbr < 0)
	{
		write(fd, "-", 1);
		nnbr *= -1;
	}
	if (nnbr != 0)
	{
		if (nnbr / 10 > 0)
			ft_putnbr_fd(nnbr / 10, fd);
		c = nnbr % 10 + 48;
		write(fd, &c, 1);
	}
	if (n == 0)
		write(fd, "0", 1);
}