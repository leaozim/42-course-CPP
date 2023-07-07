NAME	=	PmergeMe

SRCS	=	$(shell ls ./ | grep .cpp$)

OBJ_DIR	=	obj
OBJS	=	$(SRCS:%.cpp=$(OBJ_DIR)/%.o)

CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

VPATH	=	./

HEADER	=	$(shell ls ./ | grep .hpp$)

INCLUDE	=	-I ./ -I ./includes

all:		$(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
	mkdir -p $@

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 7 8 27 100 11 46 2 53 01

test: all
	./$(NAME) 7 8 27 100 11 46 2 53 01

test2: all
	./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`

clean:
			rm -rf obj

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re 