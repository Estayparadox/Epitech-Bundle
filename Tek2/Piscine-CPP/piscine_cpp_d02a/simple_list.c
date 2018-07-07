/*
** simple_list.c for simple_list in /home/pereni_j
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Sat Oct  1 11:05:54 2016 pereniguez joseph
** Last update Sat Oct  1 11:16:42 2016 pereniguez joseph
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "simple_list.h"

unsigned int list_get_size(t_list list)
{
  return ((list == NULL) ? (0) : (list_get_size(list->next) + 1));
}

t_bool list_is_empty(t_list list)
{
  return ((list == NULL) ? TRUE : FALSE);
}

void list_dump(t_list list)
{
  while (list != NULL)
    {
      printf("%f\n", list->value);
      list = list->next;
    }
}

t_bool list_add_elem_at_front(t_list *front_ptr, double elem)
{
  t_node *node;

  node = malloc(sizeof(*node));
  if (node == NULL)
    return (FALSE);
  node->value = elem;
  node->next = *front_ptr;
  *front_ptr = node;
  return (TRUE);
}

t_bool list_add_elem_at_back(t_list *front_ptr, double elem)
{
  t_node *node;
  t_list tmp;

  node = malloc(sizeof(*node));
  if (node == NULL)
    return (FALSE);
  node->value = elem;
  node->next = NULL;
  if (*front_ptr == NULL)
    *front_ptr = node;
  else
    {
      tmp = *front_ptr;
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	}
      tmp->next = node;
    }
  return (TRUE);
}

t_bool list_add_elem_at_position(t_list *front_ptr, double elem, unsigned int position)
{
  t_list list;
  t_node *node;

  if (position == 0)
    return (list_add_elem_at_front(front_ptr, elem));
  if (*front_ptr == NULL)
    return (FALSE);
  list = *front_ptr;
  while (--position)
    {
      list = list->next;
      if (list == NULL)
	return (FALSE);
    }
  node = malloc(sizeof(*node));
  node->value = elem;
  node->next = NULL;
  if (node == NULL)
    return (FALSE);
  node->next = list->next;
  list->next = node;
  return (TRUE);
}

t_bool list_del_elem_at_front(t_list* front_ptr)
{
  t_list list = *front_ptr;

  if (list == NULL)
    return (FALSE);
  *front_ptr = list->next;
  free(list);
  return (TRUE);
}

t_bool list_del_elem_at_back(t_list *front_ptr)
{
  t_list list = *front_ptr;
  t_list previous = NULL;

  if (list == NULL)
    return (FALSE);
  while (list->next)
    {
      previous = list;
      list = list->next;
    }
  if (previous)
    previous->next = NULL;
  else
    *front_ptr = NULL;
  free(list);
  return (TRUE);
}

t_bool list_del_elem_at_position(t_list* front_ptr, unsigned int position)
{
  t_list previous;
  t_list list;

  if (position == 0)
    {
      printf("front\n");
      return list_del_elem_at_front(front_ptr);
    }
  if (*front_ptr == NULL)
    return (FALSE);
  previous = *front_ptr;
  list = previous->next;
  while (--position) {
    if (list == NULL)
      return (FALSE);
    previous = list;
    list = list->next;
  }
  if (list)
    previous->next = list->next;
  free(list);
  return (TRUE);
}

double list_get_elem_at_front(t_list list)
{
  if (list == NULL)
    return (0);
  return (list->value);
}

double list_get_elem_at_back(t_list list)
{
  if (list == NULL)
    return (0);
  while (list->next)
    list = list->next;
  return (list->value);
}

double list_get_elem_at_position(t_list list, unsigned int position)
{
  if (list == NULL)
    return (0);
  while (position--)
    {
      list = list->next;
      if (list == NULL)
	return (0);
    }
  return (list->value);
}

t_node *list_get_first_node_with_value(t_list list, double value)
{
  while (list)
    {
      if (list->value == value)
	return (list);
      list = list->next;
    }
  return (NULL);
}
