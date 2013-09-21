/*
** enable_tc.c for my_select in /home/knocka_a/rendu/c/my_select
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Tue Jan 10 23:24:54 2012 antoine knockaert
** Last update Tue May 15 15:43:25 2012 antoine knockaert
*/

#include	"my.h"

void		enable_tc(char *cap)
{
  char		*tc_str;

  tc_str = tgetstr(cap, NULL);
  if (tc_str == NULL)
    printf("Error: Termcap %s not available.\n", cap);
  if (tputs(tc_str, 1, &(my_putint)) == ERR)
    printf("Error: Error on tputs.\n");
}
