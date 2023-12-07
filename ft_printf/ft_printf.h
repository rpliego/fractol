/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpliego <rpliego@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:36:25 by rpliego           #+#    #+#             */
/*   Updated: 2023/05/20 19:36:28 by rpliego          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);
int		ft_printc(int out, char c);
int		ft_printstr(int out, char *str);
int		ft_printptr(int out, void *ptr);
int		ft_printnbr(int out, int x);
int		ft_printunsigned(int out, unsigned int n);
int		ft_printhexlow(int out, unsigned int n);
int		ft_printhexup(int out, unsigned int n);

#endif 