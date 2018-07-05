/*
** reader.c for reader in /home/pereni_j/Rendu/PSU_2016_nmobjdump/objdump
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Mon Feb 28 14:21:33 2016 pereniguez joseph
** Last update Sun Feb 28 16:34:55 2016 pereniguez joseph
*/

#include "objdump.h"

void            browse_file(void *data, Elf64_Shdr *shdr, int i)
{
  unsigned char *value;
  uint32_t      oct;

  oct = 0;
  while (oct < shdr[i].sh_size)
    {
      if (oct % 16 == 0)
	printf("%06x", (unsigned int)(shdr[i].sh_addr + oct));
      if (oct % 4 == 0)
	printf(" ");
      value = data + shdr[i].sh_offset + oct;
      printf("%02x", *value);
      ++oct;
      if (oct % 16 == 0)
	{
	  show_value((void*)(data + shdr[i].sh_offset + oct - 16), 16);
	  printf("\n");
	}
    }
  if (oct % 16 != 0)
    {
      empty_char(oct);
      show_value((void*)(data + shdr[i].sh_offset + oct - (oct % 16)), (oct % 16));
    }
}

int		check_flags(Elf64_Ehdr *elf, Elf64_Shdr *shdr)
{
  int		i;
  int		value;

  i = -1;
  value = 0;
  if (elf->e_type == ET_EXEC)
    value |= 0x02;
  if (elf->e_type == ET_DYN)
    value |= 0x40 | 0x10;
  if (elf->e_phnum > 0)
    value |= 0x100;
  if (elf->e_type == ET_REL)
    value |= 0x01;
  while (++i < elf->e_shnum)
    {
      if (shdr[i].sh_type == SHT_SYMTAB)
	value |= 0x10;
    }
  return (value);
}
