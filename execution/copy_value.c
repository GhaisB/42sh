/*
** copy_value.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 15:50:04 2012 florian dell'aiera
** Last update Thu May 17 15:50:05 2012 florian dell'aiera
*/

#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"../lib/my.h"
#include	"execution.h"

void		copy_value(t_way *pt, char *type, char *filename)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  pt->c_type = xmalloc(sizeof(char) * (my_strlen(type) + 1));
  pt->c_file = xmalloc(sizeof(char) * (my_strlen(filename) + 1));
  while (type != NULL && type[i])
    pt->c_type[j++] = type[i++];
  pt->c_type[j] = '\0';
  i = 0;
  j= 0;
  while (filename != NULL && filename[i])
    pt->c_file[j++] = filename[i++];
  pt->c_file[j] = '\0';
}
