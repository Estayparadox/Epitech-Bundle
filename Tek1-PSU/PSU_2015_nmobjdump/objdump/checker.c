/*
** checker.c for checker in /home/pereni_j/Rendu/PSU_2016_nmobjdump/objdump
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Mon Feb 28 14:24:41 2016 pereniguez joseph
** Last update Sun Feb 28 16:34:18 2016 pereniguez joseph
*/

#include "objdump.h"

int		check_char(char c)
{
  if (c >= 32 && c <= 126)
    return (1);
  return (0);
}

int		check_elf(Elf64_Ehdr *elf)
{
  if (elf->e_ident[EI_MAG0] != ELFMAG0 || elf->e_ident[EI_MAG1] != ELFMAG1 ||
      elf->e_ident[EI_MAG2] != ELFMAG2 || elf->e_ident[EI_MAG3] != ELFMAG3 ||
      elf->e_ident[EI_CLASS] != ELFCLASS64 || (elf->e_type != ET_EXEC && elf->e_type
					       != ET_REL && elf->e_type != ET_DYN))
    return (0);
  return (1);
}
