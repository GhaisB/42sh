/*
** put_signal.c for put_signal in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Thu May 17 11:09:01 2012 antoine knockaert
** Last update Fri May 18 16:11:38 2012 antoine knockaert
*/

#include	<sys/types.h>
#include	<stdlib.h>
#include	<signal.h>
#include	"../42sh.h"
#include	"prompt.h"
#include	"../lib/my.h"

void		gere_signal_void()
{

}

sighandler_t	put_signal(sighandler_t handler)
{
  signal(SIGINT, handler);
  signal(SIGQUIT, handler);
  signal(SIGTSTP, &(gere_signal_void));
  return (handler);
}
