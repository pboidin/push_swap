#	Noms
NAME_PUSH_SWAP	=	push_swap
NAME_CHECKER	=	checker

#	Includes
-include make/checker.mk
-include make/includes.mk
-include make/push_swap.mk
-include make/shared.mk

#	Compilation
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror 
AR				=	ar rcs

INCLUDES_PATH	=	./includes

CHECKER_OBJS	=	$(CHECKER_SOURCES:.c=.o)
SHARED_OBJS		=	$(SHARED_SOURCES:.c=.o)
PUSH_SWAP_OBJS	=	$(PUSH_SWAP_SOURCES:.c=.o)

#	Delete
RM				=	rm -rf

#	RULES
#		Default:
all: 	$(NAME_PUSH_SWAP) $(NAME_CHECKER)

#		Convert .c to .o
%.o:	%.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

#		Compile Push_Swap Program
$(NAME_PUSH_SWAP):	$(INCLUDES) $(PUSH_SWAP_OBJS) $(SHARED_OBJS)
						@$(CC) $(CFLAGS) -I $(INCLUDES_PATH) $(PUSH_SWAP_OBJS) $(SHARED_OBJS) -o $(NAME_PUSH_SWAP)
						@echo "Push_swap Created !"

#		Compile Checker
$(NAME_CHECKER):	$(INCLUDES) $(CHECKER_OBJS) $(SHARED_OBJS)
						@$(CC) $(CFLAGS) -I $(INCLUDES_PATH) $(CHECKER_OBJS) $(SHARED_OBJS) -o $(NAME_CHECKER)
						@echo "Checker Created !"

#		Clean
clean:
						@$(RM) $(CHECKER_OBJS) $(SHARED_OBJS) $(PUSH_SWAP_OBJS)
						@echo "Cleaning all .o in project."

#		Fclean
fclean:				clean
						@$(RM) $(NAME_PUSH_SWAP) $(NAME_CHECKER)
						@echo "Cleaning compiled programs."

#		Re
re:					fclean all
						@echo "Cleaned and rebuild everything for push_swap!"

#	Generate .mk (Makefile includes)
gmk:
	@find includes -name '*.h' | sed 's/^/INCLUDES += /' > make/includes.mk
	@find srcs/shared -name '*.c' | sed 's/^/SHARED_SOURCES += /' > make/shared.mk
	@find srcs/checker -name '*.c' | sed 's/^/CHECKER_SOURCES += /' > make/checker.mk
	@find srcs/push_swap -name '*.c' | sed 's/^/PUSH_SWAP_SOURCES += /' > make/push_swap.mk

#		PHONY
.PHONY:				all clean fclean re gmk
