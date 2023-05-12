NAME	=	phonebook

SRCS	=	$(MAIN)
MAIN	=	main.cpp PhoneBook.cpp Contact.cpp Validator.cpp 

OBJ_DIR	=	obj
OBJS	=	$(SRCS:%.c=$(OBJ_DIR)/%.o)


CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3

VPATH	=	./

HEADER	=	Contact.hpp PhoneBook.hpp Validator.hpp 

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

.PHONY: all clean fclean re 