/*
** redir_left.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 15:51:15 2012 florian dell'aiera
** Last update Thu May 17 17:21:05 2012 florian dell'aiera
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

int		redir_left(t_way *pt)
{
  int		fd_files;
  int		fd_copy;
  int		acces;

  fd_files = open(pt->c_file, O_RDWR);
  if ((acces = check_access(pt->c_file)) == -1)
    return (-1);
  if (fd_files != -1)
    {
      fd_copy = check_dup(fd_files);
      if (fd_copy == -1)
	return (-1);
      check_dup2(fd_files, 0);
      check_dup2(fd_copy, 0);
    }
  if (fd_files == -1)
    return (-1);
  return (fd_files);
}
