#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>

static void	print_grps(struct passwd *pwd)
{
  gid_t		groups[1024];
  struct group	*grp;
  int		len;
  int		i;

  len = sizeof(groups);
  if (getgrouplist(pwd->pw_name, pwd->pw_gid, groups, &len) != -1)
    {
      printf(" groups=");
      for (i = 0; i < len; ++i)
	if ((grp = getgrgid(groups[i])))
	  {
	    printf("%d(%s)", groups[i], grp->gr_name);
	    if (i + 1 != len)
	      printf(",");
	  }
    }
}

static void	print_grp(__gid_t gid)
{
  struct group	*grp;

  if ((grp = getgrgid(gid)))
    printf(" gid=%d(%s)", grp->gr_gid, grp->gr_name);
}

int		main(int ac, char **av)
{
  struct passwd	*pwd;
  char		*login;

  if (!(login = getlogin())
      || !(pwd = getpwnam(ac > 1 ? av[1] : login)))
    return (1);
  printf("uid=%d(%s)", pwd->pw_uid, pwd->pw_name);
  print_grp(pwd->pw_gid);
  print_grps(pwd);
  printf("\n");
  return (0);
}
