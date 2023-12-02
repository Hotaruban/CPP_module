/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyReplace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:16:13 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/02 00:23:01 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyReplace.hpp"

myReplace::myReplace(void)
{

}

myReplace::myReplace(const std::string file)
{
	this->_file = file;
}

myReplace::~myReplace()
{

}

std::string		myReplace::replaceWord(const std::string s1, const std::string s2)
{
	std::string		result;
	std::string		line;
	std::ifstream	sourceFile;

	sourceFile.open(this->_file.c_str());
	if (!sourceFile.is_open())
	{
		std::cout << "Error: " << strerror(errno) << std::endl;
		return (NULL);
	}
	while (std::getline(sourceFile, line))
	{
		size_t pos = 0;
		size_t foundPos;

		while ((foundPos = line.find(s1, pos)) != std::string::npos)
		{
			result.append(line.substr(pos, foundPos - pos));
			result.append(s2);
			pos = foundPos + s1.length();
		}
		result.append(line.substr(pos, line.length() - pos));
		result.append("\n");
	}
	sourceFile.close();
	return (result);
}
