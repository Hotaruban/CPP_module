# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 11:14:02 by jhurpy            #+#    #+#              #
#    Updated: 2024/08/15 13:22:18 by jhurpy           ###   ########.fr        #
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
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = easy
INC = easyfind.hpp easyfind.tpp

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ) $(INC)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXECUTABLE)
	@echo "$(BGREEN)Compilation successful!"

%.o: %.cpp $(INC)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(BYELLOW)Object files removed."

fclean: clean
	@rm -f $(EXECUTABLE)
	@echo "$(BRED)Executable removed."

re: fclean all
