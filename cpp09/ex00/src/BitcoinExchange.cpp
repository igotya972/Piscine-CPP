/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:14:41 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/08 02:01:13 by dferjul          ###   ########.fr       */
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
		*this = copy;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file.is_open() || fileName.empty())
	{
		std::cout << "Error: too large a number." << std::endl;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		_data.insert(std::pair<std::string, double>(line.substr(0, 10), std::atof(line.substr(11, line.size()).c_str())));
	}
	std::map<std::string, double>::const_iterator it;
		// for (it = _data.begin(); it != _data.end(); ++it)
			// std::cout << "Date: " << it->first << " => Value: " << it->second << std::endl;
	file.close();
}

bool BitcoinExchange::parseNumbersBtc(double Numbers)
{
	if (Numbers >= 2147483648)
	{
		std::cout << "Error: too large a number." << std::endl;
		return 1;
	}
	if (Numbers < 0)
	{
		std::cout << "Error: not positif number." << std::endl;
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
	/* if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: invalid date format." << std::endl;
		return false;
	} */
	Date result = stringToInt(date);
	// std::cout << "Years: " << result.years << " Month: " << result.month << " Day: " << result.day << std::endl;
	if (result.years < 2000 || result.years > 2025)
	{
		// std::cerr << "Years: " << result.years << std::endl;
		std::cout << "Error: invalid year." << std::endl;
		return false;
	}
	if (result.day < 1 || result.day > 31)
	{
		// std::cerr << "Days: " << result.day << std::endl;
		std::cout << "Error: invalid day." << std::endl;
		return false;
	}
	
	return true;
}

double BitcoinExchange::stringToDouble(const std::string &str)
{
	char *endPtr;
	double value = std::strtod(str.c_str(), &endPtr);
	
	return (value);
}

void BitcoinExchange::loadInputFile(const std::string &fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file.is_open() || fileName.empty())
	{
		throw std::runtime_error("Error: file not found " + fileName);
	}
	std::string line;
	std::getline(file, line); // skip first line
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t sep = line.find("|");
		if (sep == std::string::npos)
		{
			std::cout << "Error: invalid line" << std::endl;
			continue;
		}
		std::string date = line.substr(0, sep);
		std::string value = line.substr(sep + 1, line.size());

		double valueV = stringToDouble(value);
		if (parseNumbersBtc(valueV))
			continue;
		if (!parseDate(date))
			continue;
		//Date result;
		// std::cerr << "Days: " << result.day << std::endl;
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
			std::cout << "Date: " << date << " => Value: " 
					<< std::fixed << std::setprecision(2) << result << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}		
	}
}