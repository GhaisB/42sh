/*
** check_dup2.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 15:49:47 2012 florian dell'aiera
** Last update Thu May 17 15:49:48 2012 florian dell'aiera
*/

#include	<unistd.h>
#include	<stdio.h>

int		check_dup2(int oldfd, int fd)
{
  int		error;

  error = dup2(oldfd, fd);
  if (error == -1)
    {
      printf("error on dup2\n");
      return (-1);
    }
  return (1);
}
