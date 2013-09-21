/*
** xwrite.c for xwrite in /home/knocka_a/repositories/42sh/lib
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Apr  9 14:09:45 2012 antoine knockaert
** Last update Mon Apr  9 14:27:14 2012 antoine knockaert
*/

#include	<unistd.h>
#include	"my.h"

int		xwrite(int fd, char *buffer, int size)
{
  int		ret;

  ret = write(fd, buffer, size);
  if (ret == -1)
    my_perror("Invalid write.", 3, 1, 1);
  return (ret);
}
