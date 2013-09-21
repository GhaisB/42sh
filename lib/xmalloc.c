/*
** xmalloc.c for xmalloc in /home/knocka_a/repositories/42sh/lib
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Apr  9 14:02:34 2012 antoine knockaert
** Last update Sun May 20 16:56:50 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"my.h"

void		*xmalloc(int size)
{
  void		*tmp;

  tmp = malloc(size);
  if (tmp == NULL)
    my_perror("Error on malloc.", 3, 1, 1);
  return (tmp);
}
