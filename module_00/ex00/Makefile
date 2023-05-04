NAME	=	megaphone

SRCS	=	$(MAIN)
MAIN	=	megaphone.cpp

OBJ_DIR	=	obj
OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)


CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

INCLUDE	=	-I ./ -I ./includes

all:		$(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
	mkdir -p $@

clean:
			rm -rf obj

fclean:		clean
			rm -f $(NAME)

re:			fclean all

git:
	git add .
	git commit -m "$(m)"
	git push

.PHONY: all clean fclean re 