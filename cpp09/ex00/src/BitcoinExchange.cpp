/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:14:41 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/24 16:33:59 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void)copy;
}

 BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		this->_data = copy._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file.is_open() || fileName.empty())
	{
		throw std::runtime_error("Error: could not open database file.");
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		_data.insert(std::pair<std::string, double>(line.substr(0, 10), std::atof(line.substr(11, line.size()).c_str())));
	}
	file.close();
}

bool BitcoinExchange::parseNumbersBtc(double Numbers)
{
	if (Numbers > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return 1;
	}
	if (Numbers < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return 1;
	}
	if (Numbers == 0)
	{
		std::cout << "Error: number is 0." << std::endl;
		return 1;
	}
	return 0;
}

Date BitcoinExchange::stringToInt(const std::string &date)
{
	Date result;
	try
	{
		result.years = std::atoi(date.substr(0, 4).c_str());
		result.month = std::atoi(date.substr(5, 2).c_str());
		result.day = std::atoi(date.substr(8, 2).c_str());
		
	}
	catch(const std::exception &e)
	{
		std::cout << "Error: invalid date conversion." << std::endl;
	}
	return result;
}

bool BitcoinExchange::parseDate(const std::string &date)
{
	if (date.size() != 11 || date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: invalid date format." << std::endl;
		return false;
	}
	Date result = stringToInt(date);
	
	if (result.years < 2009 || result.years > 2025)
	{
		std::cout << "Error: invalid year. Bitcoin not exist on " << std::endl;
		return false;
	}
	if (result.month < 1 || result.month > 12)
	{
		std::cout << "Error: invalid month." << std::endl;
		return false;
	}
	
	const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDays = daysInMonth[result.month];
	
	if (result.month == 2 && ((result.years % 4 == 0 && result.years % 100 != 0) || result.years % 400 == 0))
		maxDays = 29;
	if (result.day < 1 || result.day > maxDays)
	{
		std::cout << "Error: invalid day." << std::endl;
		return false;
	}
	
	return true;
}

double BitcoinExchange::stringToDouble(const std::string &str)
{
	double value = std::atof(str.c_str());
	
	return (value);
}

void BitcoinExchange::loadInputFile(const std::string &fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file.is_open() || fileName.empty())
		throw std::runtime_error("Error: could not open file : " + fileName);
	std::string line;
	std::getline(file, line);
	if (!line.empty() && line[line.length() - 1] == '\r')
		line = line.substr(0, line.length() - 1);
	if (line != "date | value")
	{
		throw std::runtime_error("Error: wrong format. : " + line);
	}
	std::cout << "date | value" << std::endl;
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t sep = line.find("|");
		if (sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, sep);
		if (!parseDate(date))
			continue;
		std::string value = line.substr(sep + 1, line.size());	
		double valueV = stringToDouble(value);
		if (parseNumbersBtc(valueV))
			continue;
		try
		{
			std::map<std::string, double>::const_iterator it = _data.lower_bound(date);
			if (it == _data.begin() && date < it->first)
			{
				it++;
			}
			if (it == _data.end() || date < it->first)
			{
				--it;
			}
			double result = it->second * valueV;
			std::cout << date << "=> " << valueV << " = ";
			if (result == static_cast<long long>(result))
				std::cout << static_cast<long long>(result) << std::endl;
			else
				std::cout << result << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}		
	}
}