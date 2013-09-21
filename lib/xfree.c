/*
** xfree.c for xfree in /home/knocka_a/corewar-2016-knocka_a
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sun Mar 25 13:21:12 2012 antoine knockaert
** Last update Mon Apr  9 14:43:06 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"my.h"

void		xfree(void *tmp)
{
  if (tmp != NULL)
    {
      free(tmp);
    }
}
