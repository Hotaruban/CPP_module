/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 04:12:53 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/04 01:24:16 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>

# define CSV_FILE "../data.csv"

struct exchangeRate
{
	std::string	date;
	float		quantity;
};

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();

		//void	displayData(); // TO TEST THE DATA
		void	exchangeRate(std::ifstream &file);


	private:
		std::map<std::string, float>	_data;
		static int _daysInMonth[12];
		void	_parseCSV(const std::string filename);
		bool	_validDate(const std::string &date);
		bool	_validValue(const std::string value);
		struct exchangeRate	_valueLine(std::string line);


		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
};


#endif
