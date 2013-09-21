/*
** key_funcs.c for keyfuncs in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat May 12 17:26:22 2012 antoine knockaert
** Last update Wed May 16 13:46:58 2012 antoine knockaert
*/

#include	"../42sh.h"
#include	"../lib/my.h"
#include	"prompt.h"

void		move_right(t_prompt *prompt)
{
  if (prompt->cursor < my_strlen(prompt->line))
    prompt->cursor++;
}

void		move_left(t_prompt *prompt)
{
  if (prompt->cursor > 0)
    prompt->cursor--;
}

void		delete_char(t_prompt *prompt, int offset)
{
  int		i;

  if (prompt->cursor > 0)
    {
      i = prompt->cursor - offset;
      while (prompt->line && prompt->line[i])
	{
	  prompt->line[i] = prompt->line[i + 1];
	  i++;
	}
      prompt->cursor--;
    }
}

char		*add_char_into(t_prompt *prompt, char *buffer, char *tmp)
{
  int		i;
  int		j;

  j = 0;
  i = 0;
  while (prompt->line && prompt->line[i])
    {
      if (prompt->cursor == j)
	tmp[j++] = buffer[0];
      tmp[j++] = prompt->line[i++];
    }
  if (j == prompt->cursor)
    tmp[j++] = buffer[0];
  tmp[j] = '\0';
  return (tmp);
}

void		add_char(t_prompt *prompt, char *buffer)
{
  char		*tmp;

  tmp = xmalloc(sizeof(char) * (my_strlen(prompt->line) + 2));
  if (!tmp)
    return ;
  if (prompt->line)
    tmp = add_char_into(prompt, buffer, tmp);
  else if (!prompt->line)
    {
      tmp[0] = buffer[0];
      tmp[1] = '\0';
    }
  xfree(prompt->line);
  prompt->line = tmp;
  prompt->cursor++;
}
