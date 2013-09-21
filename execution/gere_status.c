/*
** gere_status.c for 42 in /home/dell-a_f/42sh/execution
** 
** Made by florian dell'aiera
** Login   <dell-a_f@epitech.net>
** 
** Started on  Thu May 17 16:02:39 2012 florian dell'aiera
** Last update Fri May 18 01:06:10 2012 antoine knockaert
*/

#include	"execution.h"
#include	"../42sh.h"
#include	"../lib/my.h"

void		gere_status(int status)
{
  if (status == 15)
    my_putstr("Complete.\n");
  else if (status == 11 || status == 139)
    my_putstr("Segmentation Fault.\n");
  else if (status == 4 || status == 132)
    my_putstr("Illegal instruction.\n");
  else if (status == 6)
    my_putstr("Aborted.\n");
  else if (status == 13)
    my_putstr("Broken pipe.\n");
  else if (status == 9)
    my_putstr("Process killed.\n");
  else if (status == 8 || status == 136 || status == 132)
    my_putstr("Floating point exception.\n");
  else if (status == 10 || status == 138)
    my_putstr("Bus error.\n");
}
