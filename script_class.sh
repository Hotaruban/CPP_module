# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script_class.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 23:37:29 by jhurpy            #+#    #+#              #
#    Updated: 2024/02/15 17:08:32 by jhurpy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

if [ $# -eq 0 ]; then
	echo "Usage: $0 ClassName1 [ClassName2 ...] [-m]"
	exit 1
fi

create_main=false

# Parse command line options
while [ "$#" -gt 0 ]; do
	case "$1" in
		-m)
			create_main=true
			shift
			;;
		*)
			class_names+=("$1")
			shift
			;;
	esac
done

# Prompt user for the executable name
read -p "Enter the name of the executable: " executable_name

for class_name in "${class_names[@]}"; do
	# Convert class_name to uppercase
	uppercase_class_name=$(echo "$class_name" | tr '[:lower:]' '[:upper:]')

	cpp_file="${class_name}.cpp"
	hpp_file="${class_name}.hpp"

	# Check if files already exist
	if [ -e "$cpp_file" ] || [ -e "$hpp_file" ]; then
		echo "Error: Files for $class_name already exist!"
		exit 1
	fi

	# Create .cpp file
	cat > "$cpp_file" <<EOF
#include "${class_name}.hpp"

${class_name}::${class_name}()
{

}

${class_name}::${class_name}(const ${class_name}& other)
{

}

${class_name}& ${class_name}::operator=(const ${class_name}& other)
{
	if (this != &other)
	{}
	return *this;
}

${class_name}::~${class_name}()
{

}
EOF

	# Create .hpp file
	cat > "$hpp_file" <<EOF
#ifndef ${uppercase_class_name}_HPP
#define ${uppercase_class_name}_HPP

class ${class_name}
{
public:
	${class_name}();
	${class_name}(const ${class_name}& other);
	${class_name}& operator=(const ${class_name}& other);
	~${class_name}();
private:
};

#endif
EOF

	echo "Class files created for $class_name: ${cpp_file} and ${hpp_file}"
done

# Create Makefile
makefile="Makefile"
if [ ! -e "$makefile" ]; then
	cat > "$makefile" <<EOF
BRED = \033[1;31m
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BPURPLE = \033[1;35m
BBLUE = \033[1;34m
BCYAN = \033[1;36m
RESET = \033[0m

CXX = c++
CXXFLAGS = -std=c++98
SRC = ${class_names[@]/%/.cpp}
OBJ = \$(SRC:.cpp=.o)
EXECUTABLE = $executable_name

\$(EXECUTABLE): \$(OBJ)
	@\$(CXX) \$(CXXFLAGS) \$(OBJ) -o \$(EXECUTABLE)
	@echo "\$(BGREEN)Compilation successful!$(RESET)"

%.o: %.cpp %.hpp
	@\$(CXX) \$(CXXFLAGS) -c \$< -o \$@

clean:
	@rm -f \$(OBJ)
	@echo "\$(BYELLOW)Object files removed.$(RESET)"

fclean: clean
	@rm -f \$(EXECUTABLE)
	@echo "\$(BRED)Executable removed.$(RESET)"

re: fclean \$(EXECUTABLE)
EOF
	echo "Makefile created: $makefile"
fi

# Create main.cpp
main_file="main.cpp"
if [ ! -e "$main_file" ]; then
	cat > "$main_file" <<EOF
#include <iostream>
EOF

	# Include generated .hpp files
	for class_name in "${class_names[@]}"; do
		echo "#include \"${class_name}.hpp\"" >> "$main_file"
	done

	cat >> "$main_file" <<EOF

int	main(void)
{
	return (0);
}
EOF
	echo "main.cpp created: $main_file"
fi

