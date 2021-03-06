MAKEFLAGS	+=	--quiet

WHT	= \033[0;37m
BLK	= \033[0;30m
RED	= \033[0;31m
YEL	= \033[0;33m
BLU	= \033[0;34m
GRN	= \033[0;32m

NAME	=	ft_containers

# To use school main replace src/main.cpp with eval_main.cpp
SRCS	:=	src/main.cpp \
			src/test_utility.cpp \
			src/test_vector.cpp \
			src/test_map.cpp \

HEADERS	=	headers

DIR_S	=	src

DIR_O	=	obj

OBJS		:= $(SRCS:%.cpp=$(DIR_O)/%.o)

SUB_DIR_O := $(shell find $(DIR_S) -type d)
SUB_DIR_O := $(SUB_DIR_O:%=$(DIR_O)/%)

# Using wildcards: $(shell find $(HEADERS) -name *.h)
DEPS	=	$(HEADERS)/ft_containers.hpp \
			$(HEADERS)/vector.hpp \
			$(HEADERS)/map.hpp \
			$(HEADERS)/BinarySearchTree.hpp \
			$(HEADERS)/BSTiterator.hpp \
			$(HEADERS)/BSTreverse_iterator.hpp \
			$(HEADERS)/BSTnode.hpp \

CC		=	clang++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -O3
INCLUDES	= -I $(HEADERS)

RM		=	rm -f

$(DIR_O)/%.o: %.cpp
			@mkdir -p $(DIR_O)
			@mkdir -p $(SUB_DIR_O)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME):	$(DEPS) $(OBJS)
			$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)
			printf "$(WHT)[$(GRN)$(NAME) COMPILED$(WHT)]\n"

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			printf "$(WHT)[$(YEL)$(NAME) OBJS REMOVED$(WHT)]\n"

fclean:		clean
			$(RM) $(NAME)
			$(RM) -drf $(DIR_O)
			printf "$(WHT)[$(YEL)$(NAME) BINARIES REMOVED$(WHT)]\n"

re:			fclean all

stdlib:		INCLUDES += -DSTDLIB
stdlib:		NAME = std_containers
stdlib:		CFLAGS = -Wall -Wextra -Werror -std=c++11
stdlib:		clean
stdlib:		all

debug:		INCLUDES += -DDEBUG_MODE
debug:		CFLAGS = -Wall -Wextra -std=c++98 -g -fsanitize=address
debug:		clean
debug:		all

.PHONY:		all clean fclean re debug