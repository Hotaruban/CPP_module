/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:21:39 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/11 12:13:36 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyReplace.hpp"

static bool	isFileEmpty(const char *file)
{
	std::ifstream		fileStream(file);

	return (fileStream.peek() == std::ifstream::traits_type::eof());
}

int	main(int argc, char **argv)
{
	std::ofstream		destFile;
	std::string			nameDestFile;

	if (argc != 4)
		return (std::cout << "Usage: ./Sed_is_for_losers [file] [s1] [s2]" << std::endl, 1);
	if (isFileEmpty(argv[1]))
		return (std::cout << "Error: empty file" << std::endl, 1);
	myReplace			replace(argv[1]);
	if (replace.openFileFailed())
		return (std::cout << "Error: " << strerror(errno) << std::endl, 1);
	nameDestFile = std::string(argv[1]).append(".replace").c_str();
	destFile.open(nameDestFile.c_str());
	if (!destFile.is_open())
		return (std::cout << "Error: " << strerror(errno) << std::endl, 1);
	destFile << replace.replaceWord(argv[2], argv[3]);
	destFile.close();
	return (0);
}
