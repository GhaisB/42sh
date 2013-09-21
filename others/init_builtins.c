/*
** init_builtins.c for init_buitlins in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat May  5 13:43:13 2012 antoine knockaert
** Last update Sat May  5 13:55:36 2012 antoine knockaert
*/

#include        <stdlib.h>
#include        "../lib/my.h"
#include        "../42sh.h"
#include        "others.h"

int		init_builtins(t_glob *glob)
{
  glob->builtin[0] = my_strdup("exit");
  glob->builtin[1] = my_strdup("cd");
  glob->builtin[2] = my_strdup("echo");
  glob->builtin[3] = my_strdup("setenv");
  glob->builtin[4] = my_strdup("unsetenv");
  glob->builtin[5] = NULL;
  glob->builtin_fc[0] = &(my_exit);
  glob->builtin_fc[1] = &(my_cd);
  glob->builtin_fc[2] = &(my_echo);
  glob->builtin_fc[3] = &(my_setenv);
  glob->builtin_fc[4] = &(my_unsetenv);
  glob->builtin_fc[5] = NULL;
  return (1);
}
