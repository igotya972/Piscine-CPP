/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:14:33 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/08 22:06:08 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <stdexcept>
#include <stdlib.h>
#include <iomanip>
#include <sstream>

struct Date
{
	int		years;
	int		month;
	int		day;
};

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;
	public:
		//	constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange	&operator=(const BitcoinExchange &copy);
		//	methods
		void	loadDatabase(const std::string &fileName);
		void	loadInputFile(const std::string &fileName);
		double	stringToDouble(const std::string &str);
		Date	stringToInt(const std::string &date);
		// parsing
		bool	parseDate(const std::string &date);
		bool	parseNumbersBtc(double Numbers);
};
