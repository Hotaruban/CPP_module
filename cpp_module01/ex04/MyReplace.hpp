/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyReplace.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:16:16 by jhurpy            #+#    #+#             */
/*   Updated: 2023/12/02 00:20:44 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYREPLACE_HPP
# define MYREPLACE_HPP

# include <iostream>
# include <fstream>

class myReplace
{
	public:
		myReplace(void);
		myReplace(const std::string file);
		~myReplace();
		std::string		replaceWord(const std::string s1, const std::string s2);
	private:
		std::string		_file;
};

#endif
