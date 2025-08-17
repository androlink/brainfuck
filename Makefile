NAME = libbrainfuck.a

AR = ar -rcs
CC = cc
RMF = rm -f

CFLAGS = -g -Wall -Wextra -Werror
DFLAGS = -MP -MMD

SDIR = srcs
BDIR = .build
DDIR = $(BDIR)
HDIR = includes

SRCS :=
SRCS += main.c
SRCS += bf_lib/brain_fuck.c
SRCS += bf_lib/utils.c
SRCS += bf_lib/bf_parse.c
SRCS += bf_lib/bf_process.c
SRCS += bf_lib/bf_info.c


SFILES = $(SRCS:%=$(SDIR)/%)

DFILES = $(SRCS:%.c=$(DDIR)/%.d)

OFILES = $(SRCS:%.c=$(BDIR)/%.o)

all:
	@echo "compiling $(NAME):"
	@$(MAKE) -s $(NAME)

$(NAME) : $(OFILES) | $(LIB_PATH)
	$(AR) $(NAME) $?
	@echo "$(NAME) library done";

-include $(DFILES)

$(BDIR)/%.o : $(SDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I $(HDIR)/
	@echo "	$@"

clean	::
	@echo "cleaning $(NAME)";
	@$(RMF) $(OFILES) $(DFILES)

re		::	fclean
	@$(MAKE) -s all

fclean	::	clean
	@$(RMF) $(NAME)

force :

.PHONY: clean re fclean force all norm