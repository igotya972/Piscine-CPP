# Définition des couleurs
RESET   := \033[0m
RED     := \033[0;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
MAGENTA := \033[0;35m
CYAN    := \033[0;36m

SRCS	=	$(shell find ./ -name '*.cpp')

OBJ_DIR = .objs

OBJS	=	$(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))

CC	=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g -fsanitize=address -fsanitize=leak

RM	=	rm -rf

NAME	=	Animal

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

#---------------------rules---------------------#

all : $(NAME)
	@echo "$(GREEN)Compilation terminée avec succès !$(RESET)"

$(NAME) : $(OBJS)
	@echo "$(BLUE)Compilation de $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compilé avec succès !$(RESET)"

clean :
	@$(RM) $(OBJS)
	@echo "$(YELLOW)Fichiers objets supprimés.$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(RED)Exécutable et dossier objets supprimés.$(RESET)"

re : fclean all
	@echo "$(CYAN)Recompilation terminée.$(RESET)"

.PHONE : all clean fclean re