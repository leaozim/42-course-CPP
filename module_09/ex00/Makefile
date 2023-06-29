NAME	=	btc

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

clean:
			rm -rf obj

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re 