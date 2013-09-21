/*
** main.c for main in /home/knocka_a/repositories/42sh/builtins/my_cd
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Apr 30 14:41:31 2012 antoine knockaert
** Last update Sun May 20 22:36:42 2012 antoine knockaert
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	"../../42sh.h"
#include	"../../lib/my.h"

static void     cd_update_env(char *path, t_env *envp)
{
  t_env		*pwd;
  t_env		*oldpwd;

  oldpwd = NULL;
  pwd = NULL;
  oldpwd = my_getenv_ptr("OLDPWD", envp);
  pwd = my_getenv_ptr("PWD", envp);
  if (oldpwd != NULL && pwd != NULL && path)
    {
      oldpwd->data = my_strdup(pwd->data);
      if (path && path[0] == '/')
        pwd->data = my_strdup(path);
      else
        pwd->data = create_path(pwd->data, path);
    }
}

int		my_chdir(char *path, t_env *envp)
{
  struct stat           sb;

  if (stat(path, &sb) != -1)
    if (S_ISDIR(sb.st_mode))
      if (access(path, R_OK) != -1)
        if (chdir(path) != -1)
	  {
	    cd_update_env(path, envp);
	    return (1);
	  }
        else
          my_perror("cd: chdir error\n", 2, 0, 1);
      else
        my_perror("cd: Permission denied\n", 2, 0, 1);
    else
      my_perror("cd: Not a directory\n", 2, 0, 1);
  else
    my_perror("cd: No such file or directory\n", 2, 0, 1);
  return (0);
  envp = envp;
}

int		do_cd_old(t_env *envp)
{
  char		*str;

  if ((str = my_getenv("OLDPWD", envp)) != NULL)
    my_chdir(str, envp);
  else
    {
      my_perror("cd: $OLDPWD not defined, cannot proceed\n", 2, 0, 1);
      return (-1);
    }
  return (0);
}

int		do_cd_home(t_env *envp)
{
  char		*str;

  if ((str = my_getenv("HOME", envp)) != NULL)
    my_chdir(str, envp);
  else
    {
      my_perror("cd: $HOME not defined, cannot proceed\n", 2, 0, 1);
      return (-1);
    }
  return (0);
}

int		my_cd(int ac, char **av, t_glob *glob)
{
  if (ac > 2)
    {
      my_perror("cd: Usage: cd [directory]\n", 2, 0, 1);
      return (-1);
    }
  if (ac == 1)
    return (do_cd_home(glob->env));
  else if (ac == 2 && av && av[1])
    {
      if (my_match(av[1], "-"))
	return (do_cd_old(glob->env));
      else if (my_match(av[1], "~"))
	return (do_cd_home(glob->env));
      else
	return (my_chdir(av[1], glob->env));
    }
  return (0);
}
