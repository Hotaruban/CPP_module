/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:49:42 by jhurpy            #+#    #+#             */
/*   Updated: 2024/10/03 13:47:10 by jhurpy           ###   ########.fr       */
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

	try {
		yearInt = std::strtol(year.c_str(), NULL, 10);
		monthInt = std::strtol(month.c_str(), NULL, 10);
		dayInt = std::strtol(day.c_str(), NULL, 10);
	} catch (std::exception&) {
		return false;
	}

	if (yearInt < 2000 || yearInt > 9999 || monthInt < 1 || monthInt > 12)
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

	// confirm that there is only one decimal point
	size_t pos = value.find(".");
	if (pos != std::string::npos && value.find_last_of('.') != pos)
		return false;

	// confirm that there is only one 'f' at the end of the string
	pos = value.find_first_of("f");
	size_t pos2 = value.find_last_of('f');
	if (pos != std::string::npos && (pos2 != pos || pos2 != value.length() - 1))
		return false;

	// confirm that the string contains only digits, a decimal point, and an 'f'
	if (value.find_first_not_of("0123456789.f") != std::string::npos)
		return false;

	return true;
}

void BitcoinExchange::_parseCSV(const std::string filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	size_t pos;
	std::string key;
	float value;

	if (!file.is_open())
		throw std::invalid_argument(INVALID_FILE + filename);
	std::getline(file, line);
	if (file.peek() == std::ifstream::traits_type::eof())
		throw std::invalid_argument(INVALID_FILE + filename);
	if (line != "date,exchange_rate") // check if the first line is correct
		throw std::invalid_argument(INVALID_FORMAT + line);

	while (std::getline(file, line))
	{
		pos = line.find(",");
		if (pos == std::string::npos) // check if the line contains a comma
			throw std::invalid_argument(INVALID_FORMAT + line);

		key = line.substr(0, pos);
		if (!_validDate(key)) // check if the date is valid
			throw std::invalid_argument(INVALID_FORMAT + key);

		std::string valueStr = line.substr(pos + 1);
		if (!_validValue(valueStr)) // check if the value is valid
			throw std::invalid_argument(INVALID_FORMAT + line.substr(pos + 1));
		else
			value = std::strtod(valueStr.c_str(), NULL); // stod converts string to double
		if (value < 0) // check if the value is valid (positive)
		{
			std::ostringstream oss;
			oss << value;
			std::string value_str = oss.str();
			throw std::invalid_argument(INVALID_FORMAT + value_str);
		}

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
	rate = std::strtod(line.substr(pos + 2).c_str(), NULL); // stod converts string to double
	if (pos == std::string::npos || date.empty() || rate == 0) // check if the line is correct
		throw std::invalid_argument(INVALID_INPUT + line);
	if (!_validDate(date)) // check if the date is valid
		throw std::invalid_argument(INVALID_INPUT + date);
	if (!_validDate(rateStr)) // check if the value is valid
		throw std::invalid_argument(INVALID_INPUT + rateStr);
	if (rate < 0) // check if the value is valid (positive)
		throw std::invalid_argument(INVALID_VALUE);
	if (rate > 1000) // check if the value is valid (not too large)
		throw std::invalid_argument(INVALID_VALUE_TOO_LARGE);

	value.date = date;
	value.quantity = rate;

	return value; // return the date and the value as a struct
}

std::string BitcoinExchange::_rateCalculation(const struct exchangeRate & value)
{
	std::ostringstream oss;
	std::string result;
	std::map<std::string, float>::iterator it = _data.find(value.date);
	std::map<std::string, float>::iterator tmp_it;

	if (it->first != value.date && it == _data.end())
	{
		it = tmp_it = _data.begin();
		if (it->first > value.date)
			throw std::invalid_argument(INVALID_DATE + value.date);
		while (tmp_it->first != value.date && tmp_it != _data.end())
		{
			tmp_it++;
			if ((tmp_it->first > value.date || tmp_it == _data.end()) && it->first < value.date)
				break;
			it = tmp_it;
		}
	}

	oss << std::setprecision(2) << std::fixed << it->second * value.quantity;
	result = oss.str();

	size_t pos = result.find_last_not_of("0");
	if (pos != std::string::npos && result[pos] == '.')
		pos--;
	result = result.substr(0, pos + 1);

	return result; // return the exchange rate as a string
}

void BitcoinExchange::exchangeRate(std::ifstream &file)
{
	std::string line;
	struct exchangeRate value;
	std::string result;

	std::getline(file, line);
	if (line != "date | value") // check if the first line is correct
	{
		file.close();
		throw std::invalid_argument(INVALID_FORMAT + line);
	}

	while (std::getline(file, line))
	{
		try {
			value = _valueLine(line); // method to control the format of the line
			result = _rateCalculation(value); // method to calculate the exchange rate
			std::cout << value.date << " => " << value.quantity << " = " << result << std::endl;
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
