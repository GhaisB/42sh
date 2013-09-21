/*
** reset_term.c for reset_term in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon May 14 10:00:34 2012 antoine knockaert
** Last update Fri May 18 16:41:08 2012 antoine knockaert
*/

#include	"../42sh.h"
#include	"../lib/my.h"
#include	"prompt.h"

void		reset_term()
{
  struct termios	t;

  if (isatty(0))
    {
      enable_tc("ve");
      if (tcgetattr(0, &t) != -1)
	{
	  t.c_lflag |= ICANON;
	  t.c_lflag |= ECHO;
	  t.c_cc[VMIN] = 0;
	  t.c_cc[VTIME] = 0;
	  if (tcsetattr(0, TCSANOW, &t) == -1)
	    my_perror("Error on tcsetattr.\n", 2, 0, 1);
	}
      else
	my_perror("Error on tcgetattr.\n", 2, 0, 1);
    }
}
