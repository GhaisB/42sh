/*
** check_dup.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 15:51:39 2012 florian dell'aiera
** Last update Thu May 17 15:51:40 2012 florian dell'aiera
*/

#include	<unistd.h>
#include	<stdio.h>

int		check_dup(int fd)
{
  int		fd_copy;

  fd_copy = dup(fd);
  if (fd_copy == -1)
    {
      printf("error on dup\n");
      return (-1);
    }
  return (fd_copy);
}
