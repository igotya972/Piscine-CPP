#---------------------colors---------------------#

RESET   := \033[0m
RED     := \033[0;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
MAGENTA := \033[0;35m
CYAN    := \033[0;36m

#---------------------variables---------------------#

SRCS	=	$(shell find ./ -name '*.cpp')
OBJ_DIR =	.objs
OBJS	=	$(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g #-fsanitize=address -fsanitize=leak
RM		=	rm -rf
NAME	=	FragTrap

#---------------------rules---------------------#

all : $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)🔨 Compilation of $<...$(RESET)"
$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ Compilation completed.$(RESET)"
clean :
	@$(RM) $(OBJS)
	@echo "$(MAGENTA)🧹 Cleaning object files.$(RESET)"
fclean : clean
	@$(RM) $(NAME)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(RED)🗑️  Deletion of the executable and object directory.$(RESET)"
re : fclean all
.PHONY : all clean fclean re