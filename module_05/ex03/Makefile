NAME	=	bureaucrat 

SRCS	=	$(MAIN)
MAIN	=	main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
			ShrubberyCreationForm.cpp RobotomyRequestForm.cpp

OBJ_DIR	=	obj
OBJS	=	$(SRCS:%.cpp=$(OBJ_DIR)/%.o)

CC 		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

VPATH	=	./

HEADER	=	Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp \
			ShrubberyCreationForm.hpp RobotomyRequestForm.hpp

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
			rm -rf file_shrubbery

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re 