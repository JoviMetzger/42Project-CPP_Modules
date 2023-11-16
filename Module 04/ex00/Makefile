# Executable
NAME		= ex00

# Compiler and flags
CC		= c++
CPPFLAGS	= -Wall -Wextra -std=c++98
#CPPFLAGS	= -Werror
CPPFLAGS	+= -g -fsanitize=address

# Sources files
SRC		= ./src/main.cpp \
		  ./src/Animal.cpp \
		  ./src/Cat.cpp \
		  ./src/Dog.cpp \
		  ./src/WrongAnimal.cpp \
		  ./src/WrongCat.cpp

# Object Directory
OBJDIR		= obj

# Header files
HEADERDIR	= ./header

# Objects files
OBJ		= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.cpp=.o)))

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
	
$(NAME):$(OBJ) 
		$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)
		@echo "$(CORAL) $(UNDER) $(BOLD) $(ITALIC) ✨Compilation Done✨   $(RESET)"

$(OBJDIR)/%.o: ./src/%.cpp
		@mkdir -p $(OBJDIR)
		$(CC) $(CPPFLAGS) -I $(HEADERDIR) -c $< -o $@

# Define dependencies between source and header files
$(OBJDIR)/main.o: ./header/*.hpp
$(OBJDIR)/Animal.o: ./header/Animal.hpp
$(OBJDIR)/Cat.o: ./header/Cat.hpp ./header/Animal.hpp
$(OBJDIR)/Dog.o: ./header/Dog.hpp ./header/Animal.hpp
$(OBJDIR)/WrongAnimal.o: ./header/WrongAnimal.hpp
$(OBJDIR)/WrongCat.o: ./header/WrongCat.hpp

# Clean
clean:
		@rm -rf $(OBJDIR)
		@echo "$(GREEN) $(ITALIC) ✅ Cleaned object files ✅$(RESET)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(GREEN) $(ITALIC)  ✅ Removed executable ✅$(RESET)"

re:		fclean all

.PHONY: all clean fclean re
