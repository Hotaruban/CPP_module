# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 05:47:06 by jhurpy            #+#    #+#              #
#    Updated: 2023/12/02 15:26:17 by jhurpy           ###   ########.fr        #
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
SRCS = main.cpp Harl.cpp

# Header files
HDRS = Harl.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
NAME = Harl_filter

# Default target
all: $(NAME)

# Rule to build the executable
$(NAME): $(OBJS) $(HDRS)
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
