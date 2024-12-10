RESET   := \033[0m
RED     := \033[0;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
MAGENTA := \033[0;35m
CYAN    := \033[0;36m

SRCS	:=	$(shell find ./ -name '*.cpp')
OBJ_DIR :=	.objs
OBJS	:=	$(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))
CC		:=	c++
CFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
RM		:=	rm -rf
NAME	:=	MutantStack

#---------------------rules---------------------#

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)🚀 Lancement de la compilation de $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compilé avec succès !$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@echo "$(YELLOW)🔨 Compilation de $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(MAGENTA)🧹 Nettoyage des fichiers objets.$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(OBJ_DIR)
	@echo "$(RED)🗑️  Suppression de l'exécutable et du dossier objets.$(RESET)"

re: fclean all
	@echo "$(CYAN)🔄 Recompilation terminée.$(RESET)"

.PHONY: all clean fclean re