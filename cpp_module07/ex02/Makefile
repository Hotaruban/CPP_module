# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 22:20:57 by jhurpy            #+#    #+#              #
#    Updated: 2024/07/29 14:13:52 by jhurpy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BRED = \033[1;31m
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BPURPLE = \033[1;35m
BBLUE = \033[1;34m
BCYAN = \033[1;36m
RESET = \033[0m

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = main.cpp Array.tpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = array
INC = Array.hpp

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXECUTABLE)
	@echo "$(BGREEN)Compilation successful!"

%.o: %.cpp %.hpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(BYELLOW)Object files removed."

fclean: clean
	@rm -f $(EXECUTABLE)
	@echo "$(BRED)Executable removed."

re: fclean all
