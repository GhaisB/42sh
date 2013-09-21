/*
** my_putstr.c for 42sh in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Tue Apr 10 15:32:07 2012 antoine knockaert
** Last update Thu May 10 10:22:12 2012 antoine knockaert
*/

#include	<unistd.h>
#include	"my.h"

void		my_putchar(char c)
{
  xwrite(1, &c, 1);
}

void		my_putstr(char *str)
{
  if (str)
    {
      xwrite(1, str, my_strlen(str));
    }
}
