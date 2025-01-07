/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:14:41 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/07 03:47:14 by dferjul          ###   ########.fr       */
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
		throw std::runtime_error("Error: file not found " + fileName);
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

double BitcoinExchange::stringToDouble(const std::string &str)
{

	char *endPtr;
	double value = std::strtod(str.c_str(), &endPtr);
	// if (value < 0)
	// {
	// 	std::cout << "Error: not a positive number." << std::endl;
	// }
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
	std::getline(file, line);
	std::cout.unsetf(std::ios::showpoint);
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
		
		/* value.erase(0, value.find_first_not_of(" \t"));
		value.erase(value.find_last_not_of(" \t") + 1);
		
		char* endPtr;
		double valueV = std::strtod(value.c_str(), &endPtr);
		if (*endPtr != '\0' || value.empty())
		{
			std::cout << "Error: not a number." << std::endl;
			continue;
		} */
		double valueV = stringToDouble(value);
		
		if (valueV > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		try
		{
			std::map<std::string, double>::const_iterator it = _data.lower_bound(date);
			if (it == _data.begin() && date < it->first)
			{
				it++;
				// std::cout << "Error: no data found for date " << date << std::endl;
				// continue;
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