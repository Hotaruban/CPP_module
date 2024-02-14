# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 15:29:34 by jhurpy            #+#    #+#              #
#    Updated: 2024/02/14 18:58:15 by jhurpy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BRED = \033[1;31m
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BPURPLE = \033[1;35m
BBLUE = \033[1;34m
BCYAN = \033[1;36m
RESET = \033[0m

CXX = g++
CXXFLAGS = -std=c++11
SRC = Fixed.cpp main.cpp Point.cpp bsp.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = Fixed

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

re: fclean $(EXECUTABLE)
