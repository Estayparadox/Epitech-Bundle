/*
** main.c for main in /home/pereni_j/Rendu/PSU_2016_nmobjdump/objdump
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri Feb 26 18:52:25 2016 pereniguez joseph
** Last update Sun Feb 28 16:14:24 2016 pereniguez joseph
*/

#include "objdump.h"

void		objdump(char *filename)
{
  void		*data;
  Elf64_Shdr	*shdr;
  Elf64_Ehdr	*elf;
  int		fd;
  char		*strtab;

  if ((fd = open(filename, O_RDONLY)) == -1 ||
      (data = mmap(NULL, lseek(fd, 0, SEEK_END), PROT_READ, MAP_SHARED, fd, 0))
      == MAP_FAILED)
    {
      printf("objdump: '%s': No such file\n", filename);
      return ;
    }
  elf = (Elf64_Ehdr*)data;
  if (check_elf(elf) == 0)
    {
      printf("objdump: %s: File format not recognized\n", filename);
      return ;
    }
  shdr = (Elf64_Shdr*)(data + elf->e_shoff);
  strtab = (char*)(data + shdr[elf->e_shstrndx].sh_offset);
  show_format(filename, elf, shdr);
  show_sections(shdr, strtab, elf->e_shnum, data);
}

int		main(int argc, char **argv)
{
  int		i;

  i = 1;
  if (argc == 1)
    {
      objdump("a.out");
      return (EXIT_SUCCESS);
    }
  if (argc > 1)
    {
      while (argv[i])
	{
	  objdump(argv[i]);
	  ++i;
	}
    }
  return (EXIT_SUCCESS);
}
