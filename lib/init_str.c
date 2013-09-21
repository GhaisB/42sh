/*
** init_str.c for  in /home/knocka_a/korewar
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Mar 12 15:37:10 2012 antoine knockaert
** Last update Thu Apr 26 16:48:05 2012 antoine knockaert
*/

#include	"my.h"

void		init_str(char *str, int size)
{
  int		i;

  i = 0;
  while (str && i < size)
    {
      str[i] = 0;
      i++;
    }
}
