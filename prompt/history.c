/*
** history.c for history in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Wed May 16 11:20:43 2012 antoine knockaert
** Last update Thu May 17 17:45:13 2012 antoine knockaert
*/

#include	"../42sh.h"
#include	"../lib/my.h"
#include	"prompt.h"

void		hist_up(t_prompt *prompt)
{
  if (prompt->current)
    {
      prompt->line = my_strdup(prompt->current->cmd);
      prompt->cursor = my_strlen(prompt->line);
      if (prompt->current->next)
	prompt->current = prompt->current->next;
    }
}

void		hist_down(t_prompt *prompt)
{
  if (prompt->current)
    {
      prompt->line = my_strdup(prompt->current->cmd);
      prompt->cursor = my_strlen(prompt->line);
      if (prompt->current->prev)
	prompt->current = prompt->current->prev;
    }
}
