# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 00:26:21 by jhurpy            #+#    #+#              #
#    Updated: 2023/11/14 03:16:22 by jhurpy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BRED = \033[1;31m
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BPURPLE = \033[1;35m
BBLUE = \033[1;34m
BCYAN = \033[1;36m
RESET = \033[0m

# Compiler and flags
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Source files
SRCS = tests.cpp Account.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
NAME = account

# Default target
all: $(NAME)

# Rule to build the executable
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(BGREEN)Executable $(NAME) created!$(RESET)"

# Rule to build object files from source files
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	@rm -f $(OBJS) $(NAME)
	@echo "$(BRED)Cleaned!$(RESET)"

# Full clean rule
fclean: clean

# Re-build rule
re: clean all
	@echo "$(BPURPLE)Re-build!$(RESET)"

.Phony: all clean fclean re
