/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:22:19 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/02/04 17:08:52 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*	LIB */
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*ERROR TXT*/
# define ER_BUF	"GNL: wrong BUFFER_SIZE"
# define ER_OUT "GNL: terminated from outside"
# define ER_WFD "GNL: invalid FD" 	

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

char	*gnl_strdup(char *str, int len, char **store);
char	*gnl_split(char **store, int index);
char	*get_next_line(int fd);
char	*gnl_line(char *buf, char **store, int fd);

int		gnl_strlen(char *store);
int		gnl_check(char *store, int start, int rb);
int		gnl_readfile(int fd, char *buf, char **store);

void	gnl_store(char **store, char *buf, int lenst, int lenbf);
void	gnl_free(char **alloc);
#endif
