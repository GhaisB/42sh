/*
** xclose.c for xclose in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Thu May 17 12:12:48 2012 antoine knockaert
** Last update Thu May 17 12:13:32 2012 antoine knockaert
*/

#include	"my.h"

void		xclose(int fd)
{
  if (fd != -1)
    close(fd);
}
