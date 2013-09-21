/*
** end_of_way.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 15:52:00 2012 florian dell'aiera
** Last update Thu May 17 15:52:01 2012 florian dell'aiera
*/

#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"execution.h"

void		end_of_way(t_way *pt, char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (pt->way_to_exec[i])
    i++;
  pt->way_to_exec[i++] = '/';
  while (str[j])
    pt->way_to_exec[i++] = str[j++];
  pt->way_to_exec[i] = '\0';
}
