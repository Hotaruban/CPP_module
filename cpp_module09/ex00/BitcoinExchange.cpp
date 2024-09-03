/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:49:42 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/04 01:35:17 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int BitcoinExchange::_daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

BitcoinExchange::BitcoinExchange()
{
	/* data.cvs file incorrect Line 21 2009-02-29:
	https://en.wikipedia.org/wiki/Portal:Current_events/February_2009/Calendar */

	_parseCSV(CSV_FILE);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { (void)src; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

bool BitcoinExchange::_validDate(const std::string &date)
{
	int yearInt;
	int monthInt;
	int dayInt;

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	// TODO
	try {
		yearInt = /* change year to int */ 0;
		monthInt = /* change month to int */ 0;
		dayInt = /* change day to int */ 0;
	} catch (std::exception&) {
		return false;
	}

	if (yearInt < 2000 || yearInt > 2024 || monthInt < 1 || monthInt > 12)
		return false;

	bool leapYear = (yearInt % 4 == 0 && yearInt % 100 != 0) || (yearInt % 400 == 0);
	_daysInMonth[1] = leapYear ? 29 : 28;

	if (dayInt < 1 || dayInt > _daysInMonth[monthInt - 1])
		return false;

	return true;
}

bool BitcoinExchange::_validValue(const std::string value)
{
	if (value.empty())
		return false;

	size_t pos = value.find(".");
	if (pos != std::string::npos && value.find_last_not_of('.') != pos)
		return false;

	if (value.find("f") != std::string::npos)
		return false;

	// TODO
	if (value.find_first_not_of("0123456789.f") != std::string::npos)
		return false;
	if (value.find_first_of(".") != value.find_last_of("."))
		return false;
	return true;
}

void BitcoinExchange::_parseCSV(const std::string filename)
{
	std::ifstream file(filename);
	std::string line;
	size_t pos;
	std::string key;
	float value;

	if (!file.is_open())
		throw std::invalid_argument("Error: could not open file: " + filename);
	std::getline(file, line);
	if (line != "date,exchange_rate") // check if the first line is correct
		throw std::invalid_argument("Error: invalid file format: " + line);

	while (std::getline(file, line))
	{
		pos = line.find(",");
		if (pos == std::string::npos) // check if the line contains a comma
			throw std::invalid_argument("Error: invalid file format: " + line);

		key = line.substr(0, pos);
		if (!_validDate(key)) // check if the date is valid
			throw std::invalid_argument("Error: invalid file format: " + key);

		std::string valueStr = line.substr(pos + 1);
		if (!_validValue(valueStr)) // check if the value is valid
			throw std::invalid_argument("Error: invalid file format: " + line.substr(pos + 1));
		else
			value = std::stod(valueStr); // stod converts string to double
		if (value < 0) // check if the value is valid (positive)
			throw std::invalid_argument("Error: invalid file format: " + std::to_string(value));
		_data[key] = value;
	}
	file.close();
}

struct exchangeRate BitcoinExchange::_valueLine(std::string line)
{
	std::string date;
	std::string rateStr;
	float rate;
	size_t pos;
	struct exchangeRate value;

	pos = line.find(" | ");
	date = line.substr(0, pos);
	rateStr = line.substr(pos + 3);
	rate = std::stod(line.substr(pos + 2));
	if (pos == std::string::npos || date.empty() || rate == 0)
		throw std::invalid_argument("Error: invalid input => " + line);
	if (!_validDate(date))
		throw std::invalid_argument("Error: invalid input => " + date);
	if (rate < 0)
		throw std::invalid_argument("Error: not a positive number.");
	if (rate > 1000)
		throw std::invalid_argument("Error: too large a number.");
	value.date = date;
	value.quantity = rate;
	return value;
}

void BitcoinExchange::exchangeRate(std::ifstream &file)
{
	std::string line;
	struct exchangeRate value;

	std::getline(file, line);
	if (line != "date | value")
		throw std::invalid_argument("Error: invalid file format: " + line);
	while (std::getline(file, line))
	{
		try {
			// method to control the format of the line
			value = _valueLine(line);
			std::cout << value.date << " => " << value.quantity << std::endl;
			// methode to find the date and the rate
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	file.close();
}

// FOR TESTING PURPOSES
//void BitcoinExchange::displayData()
//{
//	int i = 0;

//	for (std::map<std::string, double>::iterator it = _data.begin(); it != _data.end(); it++)
//	{
//		i++;
//		std::cout << it->first << " : " << std::setprecision(2) << std::fixed << it->second << std::endl;
//		if (i == 10)
//			break;
//	}
//}
