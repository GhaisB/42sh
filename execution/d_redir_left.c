/*
** d_redir_left.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 15:50:26 2012 florian dell'aiera
** Last update Fri May 18 05:56:51 2012 maxime sauvage
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/stat.h>
#include	<sys/types.h>
#include	<fcntl.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

int		d_redir_left(t_way *pt)
{
  int		pipefd[2];
  char		*buff;
  int		pos;
  char		*end;

  buff = xmalloc(1025 * sizeof(char));
  check_dup(0);
  check_pipe(pipefd);
  end = concat(pt->c_file, "\n");
  while (my_match(buff, end) != 1)
    {
      my_putstr("?>");
      pos = xread(0, buff, 1000);
      buff[pos] = '\0';
      if (my_match(buff, end) != 1)
	{
	  if (write(pipefd[1], buff, my_strlen(buff)) == -1)
	    my_putstr("Error on write\n");
	}
    }
  free(buff);
  xclose(pipefd[1]);
  check_dup2(pipefd[0], 0);
  return (1);
}
