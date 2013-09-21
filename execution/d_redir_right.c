/*
** d_redir_right.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 16:06:31 2012 florian dell'aiera
** Last update Thu May 17 17:21:15 2012 florian dell'aiera
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

int		d_redir_right(t_way *pt)
{
  int		fd_files;
  int		fd_copy;
  int		acces;
  int		right;

  right = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
  fd_files = open(pt->c_file, O_CREAT | O_WRONLY | O_APPEND, right);
  if ((acces = check_access(pt->c_file)) == -1)
    return (-1);
  if (fd_files != -1)
    {
      fd_copy = check_dup2(fd_files, 1);
      if (fd_copy == -1)
	return (-1);
    }
  if (fd_files == -1)
    return (-1);
  return (fd_files);
}
