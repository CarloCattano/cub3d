/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrotbe <jstrotbe@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:10:47 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/06 13:43:02 by jstrotbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H

# define CUBE3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define ERROR_ARG "CUBE3D NEEDS ONLY ONE ARG"
# define ERROR_PARS "PARSING FAILD"
# define ERROR_FILE "CUB FILE CORRUPTED" 
# define ERROR_CUB "FILE NEED .CUB EXTENSION"
# define ERROR_FILE_OPEN "OPEN CUB FILE FAIL"

int     cub_error(char const *msg, void (*f)(), void *ptr);
int		cub_parser(char *input);


#endif	
