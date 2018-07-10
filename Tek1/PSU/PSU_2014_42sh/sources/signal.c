/*
** signal.c for 42sh in /home/arrazo_p/semestre2/SystemeUnix/PSU_2014_minishell2
** 
** Made by arrazolaleon pedroantonio
** Login   <arrazo_p@epitech.net>
** 
** Started on  Thu Mar  5 16:48:28 2015 arrazolaleon pedroantonio
** Last update Sun May 24 14:54:30 2015 Vatinelle Maxime
*/

#include "../42sh.h"

void		ctrl_c()
{
  my_putstr("\n");
  my_print_prompt();
  return ;
}
