/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyReplace.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:16:16 by jhurpy            #+#    #+#             */
/*   Updated: 2024/02/15 14:56:11 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYREPLACE_HPP
# define MYREPLACE_HPP

# include <iostream>
# include <fstream>
# include <cstring>

class myReplace
{
	public:
		myReplace(void);
		myReplace(const std::string file);
		~myReplace();
		bool			openFileFailed();
		std::string		replaceWord(const std::string s1, const std::string s2);
	private:
		std::ifstream	_file;
		bool			_openFailed;
};

#endif
