# Executable
NAME 		= ex01

# Compiler and flags
CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
CPPFLAGS	+= -g -fsanitize=address

# Sources files
SRC			= main.cpp \
				Fixed.cpp \

# Object Directory
OBJDIR 		= obj

# Objects files
OBJ			= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.cpp=.o)))

# Colors
BOLD		= \033[1m
ITALIC		= \033[3m
UNDER 		= \033[4m
GREEN		= \033[32;1m
INDIGO		= \033[38;2;75;0;130m
CORAL		= \033[38;2;255;127;80m
RESET		= \033[0m

# Targets
all: $(NAME)
	
$(NAME): $(OBJ) 
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)
	@echo "$(CORAL) $(UNDER) $(BOLD) $(ITALIC) ✨Compilation Done✨   $(RESET)"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

# Clean
clean:
		@rm -rf $(OBJDIR)
		@echo "$(GREEN) $(ITALIC) ✅ Cleaned object files ✅$(RESET)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(GREEN) $(ITALIC)  ✅ Removed executable ✅$(RESET)"

re:		fclean all

.PHONY: all clean fclean re
