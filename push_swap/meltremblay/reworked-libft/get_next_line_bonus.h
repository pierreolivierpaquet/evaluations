/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:28:08 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/27 10:10:50 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include"../reworked-libft/libft.h"

char	*get_next_line(int fd);
char	*ft_line_join(char *doc_str, char *bufferlen);
char	*read_fd(int fd, char *doc);
char	*delete_first_line(char *doc);
char	*get_line(char *doc);

#endif
