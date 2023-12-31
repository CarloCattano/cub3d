/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlo <carlo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:10:47 by jstrotbe          #+#    #+#             */
/*   Updated: 2023/11/27 00:25:23 by carlo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

/* ERROR MSG */
# define E_ "ERROR"	

/* GENERAL ERROR */
# define E_MAL	"MALLOC_FAIL"

/* MAIN */
# define E_ARG "CUBE3D NEEDS ONLY ONE ARG"

/* PARSER */
# define E_PARS "PARSING FAILED"

/*GENERAL FILE */
# define E_FILE "CUB FILE CORRUPTED" 
# define E_CUB "FILE NEEDS .CUB EXTENSION"
# define E_FO "OPEN CUB FILE FAIL"
# define E_FC "FILE IS NOT RIGHT CONFIGURED"

/* MSG CUB FILE */
# define E_NE "NO EXTRAS SURPORTED IN THIS MODE"		
# define E_SDT ".CUB HAS DUPLICATE TYPES "
# define E_SARG ".CUB TYPE HAS NOT THE RIGHT NUMBER OF ARG"
# define E_SWARG ".CUB TYPE ARG IS WRONG"		
# define E_SDC ".CUB HAS DUPLICATE COLOUR "
# define E_SWC ".CUB WRONG COLOUR INPUT "	
# define E_SOTF ".CUB OPEN TEXTURE FAIL"
# define E_SMT "NOT ALL NECESSARY TYPES ARE DECLAIRED BEFORE MAP"

/* MAP */
# define E_MF "MAP IS NOT CORRECT"
# define E_NP "NO PLAYER"
# define E_MP "MULTIPLE PLAYERS"
# define E_MW "MAP NOT ENCLOSED BY WALLS"

/* INIT */
# define E_IN "INIT FAILIURE"
# define E_WL "LOAD WEAPON FAIL"
#endif
