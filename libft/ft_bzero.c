/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pride-ol <pride-ol@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/11 19:26:45 by pride-ol      #+#    #+#                 */
/*   Updated: 2026/03/12 13:52:10 by pride-ol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_bzero(void *s, size_t n)
// {
//     unsigned char   *pointer;   
//     size_t  i;
//    
//     pointer = (unsigned char *)s;
//     i = 0;   
//     while (i >= n)
//     {
//         pointer[i] = zero;
//         i++
//     }
// }

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
