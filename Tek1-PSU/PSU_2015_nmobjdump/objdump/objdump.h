/*
** objdump.h for objdump in /home/pereni_j/Rendu/PSU_2016_nmobjdump/objdump
**
** Made by pereniguez joseph
** Login   <pereni_j@epitech.net>
**
** Started on  Fri Feb 26 19:44:30 2016 pereniguez joseph
** Last update Sun Feb 28 16:26:33 2016 pereniguez joseph
*/

#ifndef __OBJDUMP_H__
# define __OBJDUMP_H__

# include <elf.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <string.h>

void	show_sections(Elf64_Shdr*, char*, int, void*);
void	browse_file(void*, Elf64_Shdr*, int);
void	empty_char(int);
void	show_value(void*, uint32_t);
void	show_format(char*, Elf64_Ehdr*, Elf64_Shdr*);
void	show_flags(Elf64_Ehdr*, Elf64_Shdr*);
int	check_flags(Elf64_Ehdr*, Elf64_Shdr*);
int	check_char(char);
int	check_elf(Elf64_Ehdr*);

#endif /* __OBJDUMP_H__ */
