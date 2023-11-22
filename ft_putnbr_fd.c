/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:46:26 by akyoshid          #+#    #+#             */
/*   Updated: 2023/11/22 20:23:57 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	ones_place;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	ones_place = (n % 10) + '0';
	n /= 10;
	if (n > 0)
		ft_putnbr_fd(n, fd);
	write (fd, &ones_place, 1);
}

// int	main(void)
// {
// 	int	num;

// 	num = INT_MAX;
// 	printf("%d\n", num);
// 	ft_putnbr_fd(num, 1);
// 	return (0);
// }
