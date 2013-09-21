/*
** basic_prompt.c for basic_prompt in /home/knocka_a/repositories/42sh/prompt
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Wed May  2 16:57:51 2012 antoine knockaert
** Last update Sun May 20 15:32:46 2012 antoine knockaert
*/

#include	<sys/types.h>
#include	<signal.h>
#include	"../lib/my.h"
#include	"../42sh.h"
#include	"prompt.h"

void            gere_signal_termcap()
{
  kill(-10, SIGINT);
}

void		gere_key(t_prompt *prompt, char *buffer)
{
  if (my_strlen(buffer) == 1 && buffer[0] >= 32 && buffer[0] < 127)
    add_char(prompt, buffer);
  else if (buffer[0] == 10)
    prompt->enter = 0;
  else if (buffer[0] == 127)
    delete_char(prompt, 1);
  else if (buffer[0] == 27 && buffer[1] == 91
	   && buffer[2] == 51 && buffer[3] == 126)
    delete_char(prompt, 0);
  else if (buffer[0] == 12)
    enable_tc("cl");
  else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68)
    move_left(prompt);
  else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67)
    move_right(prompt);
  else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65)
    hist_up(prompt);
  else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66)
    hist_down(prompt);
}

void		aff_prompt_cursor(t_prompt *prompt)
{
  if (prompt->cursor == my_strlen(prompt->line))
    {
      enable_tc("mr");
      my_putchar(' ');
      enable_tc("me");
    }
}

void		aff_prompt(t_prompt *prompt)
{
  int		i;

  enable_tc("cd");
  my_putstr("\r");
  my_putstr(prompt->prompt);
  i = 0;
  while (prompt->line && prompt->line[i])
    {
      if (i == prompt->cursor)
	enable_tc("mr");
      my_putchar(prompt->line[i]);
      if (i == prompt->cursor)
	enable_tc("me");
      i++;
    }
  aff_prompt_cursor(prompt);
}

char		*termcap_prompt(t_glob *glob, t_prompt *prompt)
{
  char		buffer[15];
  int		ret;

  enable_tc("vi");
  aff_prompt(prompt);
  while (prompt->enter)
    {
      put_signal(&(gere_signal_termcap));
      init_str(buffer, 15);
      if ((ret = read(0, buffer, 10)) != -1)
	{
	  if (buffer[0] == 4)
	    {
	      glob->exit = 1;
	      return (NULL);
	    }
	  buffer[ret] = 0;
	  gere_key(prompt, buffer);
	  aff_prompt(prompt);
	}
    }
  my_putstr("\b \n");
  return (prompt->line);
}
