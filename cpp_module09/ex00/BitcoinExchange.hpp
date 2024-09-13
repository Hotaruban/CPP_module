/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 04:12:53 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/13 18:52:06 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <sstream>
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
		void			_parseCSV(const std::string filename);
		bool			_validDate(const std::string &date);
		bool			_validValue(const std::string value);
		std::string		_rateCalculation(const struct exchangeRate & value);
		struct exchangeRate	_valueLine(std::string line);

		static int		_daysInMonth[12];
		std::map<std::string, float>	_data;

		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
};


#endif
