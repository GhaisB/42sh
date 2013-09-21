/*
** xread.c for xread in /home/knocka_a/repositories/42sh/lib
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Apr  9 14:23:17 2012 antoine knockaert
** Last update Mon Apr  9 14:27:29 2012 antoine knockaert
*/

#include	<unistd.h>
#include	"my.h"

int		xread(int fd, char *buffer, int size)
{
  int		ret;

  ret = read(fd, buffer, size);
  if (ret == -1)
    my_perror("Invalid read.", 3, 1, 1);
  return (ret);
}
