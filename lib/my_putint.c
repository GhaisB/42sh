/*
** my_putint.c for my_putint in /home/knocka_a/rendu/c/my_select
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Tue Jan 10 23:29:37 2012 antoine knockaert
** Last update Thu May 10 10:21:24 2012 antoine knockaert
*/

#include	"my.h"

int		my_putint(int i)
{
  char		c;

  c = (char) i;
  my_putchar(c);
  return (0);
}
