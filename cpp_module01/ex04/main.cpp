/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:21:39 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/02 00:26:45 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyReplace.hpp"

int	main(int argc, char **argv)
{
	std::ofstream		destFile;
	std::string			nameDestFile;
	myReplace			replace(argv[1]);

	if (argc != 4)
		return (std::cout << "Usage: ./Sed_is_for_losers [file] [s1] [s2]" << std::endl, 1);
	nameDestFile = std::string(argv[1]).append(".replace");
	destFile.open(nameDestFile.c_str());
	if (!destFile.is_open())
		return (std::cout << "Error: " << strerror(errno) << std::endl, 1);
	destFile << replace.replaceWord(argv[2], argv[3]);
	destFile.close();
	return (0);
}


//std::string		replaceWord(const std::string str, const std::string s1, const std::string s2)
//{
//	std::string		result;
//	std::string		line;
//	std::ifstream	sourceFile;

//	sourceFile.open(str, O_RDONLY);
//	if (errno)
//	{
//		std::cout << "Error: " << strerror(errno) << std::endl;
//		return (NULL);
//	}
//	while (std::getline(sourceFile, line))
//	{
//		size_t pos = 0;
//		size_t foundPos;

//		while ((foundPos = line.find(s1, pos)) != std::string::npos)
//		{
//			result.append(line.substr(pos, foundPos - pos));
//			result.append(s2);
//			pos = foundPos + s1.length();
//		}
//		result.append(line.substr(pos));
//		result.append("\n");
//	}
//	return (result);
//}

//int	main(int argc, char **argv)
//{
//	std::ifstream		nameSourceFile;
//	std::ofstream		destFile;
//	std::string			nameSourceFile;
//	const char			*nameDestFile;

//	if (argc != 4)
//		return (std::cout << "Wrong number of arguments" << std::endl, 1);
//	nameSourceFile.open(argv[1]);
//	if (!nameSourceFile.is_open())
//	{
//		std::cout << "Error: " << strerror(errno) << std::endl;
//		return (1);
//	}
//	nameDestFile = nameSourceFile.append(".replace").c_str();
//	destFile.open(nameDestFile);
//	if (errno)
//	{
//		std::cout << "Error: " << strerror(errno) << std::endl;
//		return (1);
//	}
//	destFile << replaceWord(argv[1], argv[2], argv[3]);
//	destFile.close();
//	return (0);
//}

