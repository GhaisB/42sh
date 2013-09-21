/*
** init_config.c for init_config in /home/knocka_a/repositories/42sh
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Tue Apr 10 14:00:00 2012 antoine knockaert
** Last update Sun May 20 15:04:59 2012 florian dell'aiera
*/

#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<pwd.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"../lib/my.h"
#include	"../42sh.h"
#include	"others.h"

int	open_configfile(char *configname, int flags, int rights)
{
  int		fd;
  uid_t		uid;
  struct passwd *passwd;
  char		*filename;
  char		*home;
  char		*error;

  uid = getuid();
  passwd = getpwuid(uid);
  if (passwd != NULL)
    {
      if (passwd->pw_dir[my_strlen(passwd->pw_dir) - 1] != '/')
	home = concat(passwd->pw_dir, "/");
      else
	home = my_strdup(passwd->pw_dir);
      filename = concat(home, configname);
      xfree(home);
    }
  fd = open(filename, flags, rights);
  error = concat(filename, ": Cannot read the configuration file (Ignored).\n");
  if (fd == -1)
    my_perror(error, 1, 0, 1);
  xfree(filename);
  xfree(error);
  return (fd);
}

void		gere_config_line(t_glob *glob, char *str, int line)
{
  char		*str2;
  char		**a;

  str2 = epur_str(str, 0, COMMENT_CHAR);
  a = my_str_to_wordtab(str2, ' ');
  if (a && my_strlen(str2) > 0)
    {
      if (a && a[0] && my_match(a[0], "alias"))
	add_alias(glob, str2);
      else
	add_var_list(glob, str2, line);
    }
  xfree(str2);
  free_wtb(a);
}

void		init_config(t_glob *glob)
{
  int		fd;
  int		i;
  char		**c;

  i = 0;
  fd = open_configfile(CONFIG_NAME, O_RDWR, 0);
  if (fd != -1)
    {
      c = read_all(fd);
      while (c && c[i])
	{
	  gere_config_line(glob, c[i], i + 2);
	  i++;
	}
      free_wtb(c);
      xclose(fd);
    }
}
