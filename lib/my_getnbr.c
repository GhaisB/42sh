/*
** my_getnbr.c for My_Lib in /home/knocka_a//rendu/lib/my
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Tue Oct 11 17:54:22 2011 antoine knockaert
** Last update Sat Nov 19 17:36:35 2011 antoine knockaert
*/
#include "my.h"

int	my_getnbr(char *str)
{
  int	pos;
  int	signe;
  int	nbr;

  pos = 0;
  signe = 1;
  while (str[pos] != '\0' && (str[pos] == '+' || str[pos] == '-'))
    {
      if (str[pos] == '-')
	{
	  signe = signe * -1;
	}
      pos++;
    }
  str = str + pos;
  pos = 0;
  nbr = 0;
  while (str[pos] >= '0' && str[pos] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr - (str[pos] - 48);
      pos++;
    }
  return (nbr * signe * -1);
}
