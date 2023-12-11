/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyReplace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:16:13 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/11 12:13:30 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyReplace.hpp"

// protect file in case of empty file

myReplace::myReplace(void)
{

}

myReplace::myReplace(const std::string file)
{
	this->_file.open(file.c_str());
	if (!this->_file.is_open())
		this->_openFailed = true;
	else
		this->_openFailed = false;
}

myReplace::~myReplace()
{
	this->_file.close();
}

bool		myReplace::openFileFailed()
{
	return (this->_openFailed);
}

std::string		myReplace::replaceWord(const std::string s1, const std::string s2)
{
	std::string		result;
	std::string		line;

	while (std::getline(this->_file, line))
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
	return (result);
}
