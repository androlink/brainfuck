NAME = brainfuck

CC = cc
RMF = rm -f

CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address,leak
DFLAGS = -MP -MMD

SDIR = srcs
BDIR = .build
DDIR = $(BDIR)
HDIR = includes

SRCS :=

SFILES = $(SRCS:%=$(SDIR)/%)

DFILES = $(SRCS:%.c=$(DDIR)/%.d)

OFILES = $(SRCS:%.c=$(BDIR)/%.o)

LIB_FLAGS := 

include config/srcs.mk

all:
	@echo "compiling $(NAME):"
	@$(MAKE) -s $(NAME)

$(NAME) : $(OFILES) | $(LIB_PATH)
	$(CC) $(CFLAGS) -o $@ $(OFILES) $(LIB_FLAGS)
	@echo "$(NAME) compilation done";

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

-include config/update.mk

.PHONY: clean re fclean force all norm