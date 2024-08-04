SRCS	=	$(shell find ./ -name '*.cpp')

OBJ_DIR = OBJS

OBJS	=	$(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))

CC	=	g++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM	=	rm -rf

NAME	=	phonebook

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

#---------------------rules---------------------#

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_DIR)

re : fclean all

.PHONE : all clean fclean re