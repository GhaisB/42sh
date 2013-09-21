/*
** error.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 16:02:18 2012 florian dell'aiera
** Last update Fri May 18 13:48:35 2012 antoine knockaert
*/

#include	<stdio.h>
#include	"../parser/parser.h"
#include	"../42sh.h"
#include	"execution.h"

int		error(int i)
{
  if (i == 0)
    {
      printf("42sh: Command not found.\n");
      return (0);
    }
  return (1);
}
