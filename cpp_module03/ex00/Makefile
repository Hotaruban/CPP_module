BRED = \033[1;31m
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BPURPLE = \033[1;35m
BBLUE = \033[1;34m
BCYAN = \033[1;36m
RESET = \033[0m

CXX = g++
CXXFLAGS = -std=c++11
SRC = ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = ClapTrap

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
