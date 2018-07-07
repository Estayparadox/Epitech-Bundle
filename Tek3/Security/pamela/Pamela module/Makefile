RM		= rm -f

CC		= gcc

SRC		= pam_module.c

NAME		= pam_module.so

SOPATH		= /lib/security/

AUTHPATH	= /etc/pam.d/common-auth

PASSPATH	= /etc/pam.d/common-password

SESSPATH	= /etc/pam.d/common-session

GETPAMPKGS	= apt-get install libpam0g-dev

OBJ		= my_pam.o

LDFLAGS		+= -x --shared

CFLAGS		+= -W -Wall -Wextra -Werror -I./include -fPIC

all:		$(NAME)

$(NAME):
		$(CC) -c $(SRC) $(CFLAGS) -o $(OBJ)
		ld $(LDFLAGS) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)
		$(RM) $(NAME)
		$(RM) *~

fclean:		clean
		$(RM) $(NAME)

re:		clean all

install:
		@printf "\n=> Installing libs\n"
		@apt-get -qq install gcc
		@apt-get -qq install libpam0g-dev
		@apt-get -qq install cryptsetup
		@apt-get -qq install libcryptsetup-dev
		@printf "  => \033[0;32mDONE\033[0m\n"
		@printf "=> Installing $(NAME)\n"
		@printf "  => Adding $(NAME)\n"
		@[ -d $(SOPATH) ] || mkdir $(SOPATH)
		cp $(NAME) $(SOPATH)
		chown root:root $(SOPATH)$(NAME)
		chmod 755 $(SOPATH)$(NAME)
		@printf "    => \033[0;32mDONE\033[0m\n"
		@printf "  => Configuring $(NAME)\n"
		@(grep -q $(NAME) $(AUTHPATH)) || echo >> $(AUTHPATH)
		@(grep -q $(NAME) $(AUTHPATH)) || echo "auth required" $(NAME) >> $(AUTHPATH)
		@(grep -q $(NAME) $(PASSPATH)) || echo >> $(PASSPATH)
		@(grep -q $(NAME) $(PASSPATH)) || echo "password required" $(NAME) >> $(PASSPATH)
		@(grep -q $(NAME) $(SESSPATH)) || echo >> $(SESSPATH)
		@(grep -q $(NAME) $(SESSPATH)) || echo "session required" $(NAME) >> $(SESSPATH)
		@printf "    => \033[0;32mDONE\033[0m\n"
		@printf "=> Installation complete\n\n"

uninstall:
		@printf "\n=> Uninstalling $(NAME)\n"
		@printf "  => Removing $(NAME)\n"
		@[ -f $(SOPATH)$(NAME) ] && $(RM) $(SOPATH)$(NAME) || echo "Module $(NAME) already removed"
		@printf "    => \033[0;32mDONE\033[0m\n"
		@printf "  => Reconfiguring default parameters\n"
		@grep -v $(NAME) $(AUTHPATH) > $(AUTHPATH).tmp
		@mv $(AUTHPATH).tmp $(AUTHPATH)
		@grep -v $(NAME) $(PASSPATH) > $(PASSPATH).tmp
		@mv $(PASSPATH).tmp $(PASSPATH)
		@grep -v $(NAME) $(SESSPATH) > $(SESSPATH).tmp
		@mv $(SESSPATH).tmp $(SESSPATH)
		@printf "    => \033[0;32mDONE\033[0m\n"
		@printf "=> Uninstallation complete\n\n"

test:
		@printf "\n=> Testing...\n"
		@printf "  => \033[0;32mDONE\033[0m\n\n"		

check:
		@printf "\n=> Start of checks\n"
		@printf "  => Checking if $(NAME) is installed\n"
		@[ -f $(SOPATH)$(NAME) ] && echo $(NAME) " is \033[0;32mINSTALLED\033[0m" || echo $(NAME) "is \033[0;31mNOT INSTALLED\033[0m"
		@printf "  => Checking common files\n"
		@(grep -q $(NAME) $(AUTHPATH)) && echo "common-auth: \033[0;32mUP-TO-DATE FILE\033[0m" || echo "common-auth: \033[0;31mORIGINAL DRAFT\033[0m"
		@(grep -q  $(NAME) $(PASSPATH)) && echo "common-password: \033[0;32mUP-TO-DATE FILE\033[0m" || echo "common-password: \033[0;31mORIGINAL DRAFT\033[0m"
		@(grep -q $(NAME) $(SESSPATH)) && echo "common-session: \033[0;32mUP-TO-DATE FILE\033[0m" || echo "common-session: \033[0;31mORIGINAL DRAFT\033[0m"
		@printf "=> End of checks\n\n"
