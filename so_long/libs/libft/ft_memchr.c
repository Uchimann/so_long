/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:03:40 by icelebi           #+#    #+#             */
/*   Updated: 2023/06/07 18:03:41 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	int				i;
	unsigned char	*s;

	s = (unsigned char *)ptr;
	i = 0;
	while (n > 0)
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
		n--;
	}
	return ((void *) NULL);
}
