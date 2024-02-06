/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermolo <alermolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:14:50 by alermolo          #+#    #+#             */
/*   Updated: 2024/01/28 15:36:04 by alermolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdarg.h>

char	*ft_strndup(char *src, int n);
char	**ft_split(char *str, char *charset);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strjoin_free(char const *s1, char const *s2);
void	*ft_bzero(void *s, size_t n);
void	*free_and_null(char *s);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_printf(const char *s, ...);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printaddr(unsigned long long addr);
int		ft_printnbr(int n);
int		ft_printnbr_unsigned(unsigned int n);
int		ft_printnbr_hex(unsigned int nbr);
int		ft_printnbr_hex_caps(unsigned int nbr);
char	*ft_itoa(int n);

#endif
