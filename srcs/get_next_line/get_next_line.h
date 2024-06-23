/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:45 by sshimura          #+#    #+#             */
/*   Updated: 2024/06/19 14:41:41 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*check_newline(char **leftover);
char	*read_and_join(int fd, char **leftover);
char	*finalize_line(char **leftover);
char	*handle_read(char *buf, char **leftover);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	ft_strcpy(char *dst, char *src);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif