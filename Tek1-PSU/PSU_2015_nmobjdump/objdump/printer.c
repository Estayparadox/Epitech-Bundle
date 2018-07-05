/*
** printer.c for printer in /home/pereni_j/Rendu/PSU_2016_nmobjdump/objdump
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Mon Feb 28 13:09:23 2016 pereniguez joseph
** Last update Sun Feb 28 16:34:46 2016 pereniguez joseph
*/

#include "objdump.h"

void            show_flags(Elf64_Ehdr *elf, Elf64_Shdr *shdr)
{
  int           i;

  i = -1;
  if (elf->e_type == ET_EXEC)
    printf("EXEC_P ");
  if (elf->e_type == ET_REL)
    printf("HAS_RELOC ");
  while (++i < elf->e_shnum)
    {
      if (shdr[i].sh_type == SHT_SYMTAB)
	printf("HAS_SYMS ");
    }
  if (elf->e_type == ET_DYN)
    printf("HAS_SYMS DYNAMIC ");
  if (elf->e_phnum > 0)
    printf("D_PAGED ");
}

void            empty_char(int i)
{
  uint32_t      epc;

  epc = i % 16;
  while (epc < 16)
    {
      printf("  ");
      if (epc % 4 == 0)
	printf(" ");
      ++epc;
    }
}

void		show_value(void *data, uint32_t size)
{
  uint32_t	i;
  char		*str;

  i = 0;
  printf(" ");
  while (i < size)
    {
      str = data + i;
      if (check_char(*str) == 1)
	printf("%c", *str);
      else
	printf(".");
      ++i;
    }
}

void            show_format(char *filename, Elf64_Ehdr *info, Elf64_Shdr *shdr)
{
  printf("\n%s:%5cfile format %s\n", filename, ' ',
	 info->e_type == ELFCLASS64 ? "elf64-x86-64" : "elf32-x86-64");
  printf("architecture: %s, flags 0x%08x:\n",
	 info->e_machine == EM_X86_64 ? "i386:x86-64" : "unknown",
	 check_flags(info, shdr));
  show_flags(info, shdr);
  printf("\n");
  printf("start address 0x%016x\n", (unsigned int)info->e_entry);
}

void            show_sections(Elf64_Shdr *shdr, char *strtab, int shnum, void *data)
{
  int           i;

  i = 0;
  while (i < shnum)
    {
      if (strlen(&strtab[shdr[i].sh_name]) != 0
	  && strcmp(&strtab[shdr[i].sh_name], ".strtab")
	  && strcmp(&strtab[shdr[i].sh_name], ".symtab")
	  && strcmp(&strtab[shdr[i].sh_name], ".shstrtab")
	  && strcmp(&strtab[shdr[i].sh_name], ".bss"))
	{
	  printf("\nContent of section %s:\n", &strtab[shdr[i].sh_name]);
	  browse_file(data, shdr, i);
	}
      ++i;
    }
  printf("\n");
}
