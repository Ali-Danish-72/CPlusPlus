###############################################################################
#                                  VARIABLES                                  #
###############################################################################
NAME = iter
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RESET=\033[0m
RED=\033[1;31m
GREEN=\033[1;32m
BLUE=\033[1;34m
CYAN=\033[1;36m
SRCS_DIR = sources/
SRCS = main.cpp
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS_DIR = objects/
OBJS = $(SRCS:%.cpp=%.o)
OBJS_PATH = $(addprefix $(OBJS_DIR), $(OBJS))

###############################################################################
#                                     RULES                                   #
###############################################################################

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS_PATH)
	@$(CXX) $(CXXFLAGS) $(OBJS_PATH) -o $(NAME)
	@echo "$(BLUE)OBJECTS $(GREEN)CREATED$(RESET)"
	@echo "$(BLUE)PROGRAM $(GREEN)CREATED: $(CYAN)$(NAME)$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_PATH): $(SRCS_PATH)
	@make -s $(OBJS)

$(OBJS):
	@$(CXX) $(CXXFLAGS) -c $(SRCS_DIR)$(@:%.o=%.cpp) -o $(OBJS_DIR)$@

clean:
	@echo "$(BLUE)OBJECTS $(RED)DESTROYED$(RESET)"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)PROGRAM $(RED)DESTROYED: $(CYAN)$(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re