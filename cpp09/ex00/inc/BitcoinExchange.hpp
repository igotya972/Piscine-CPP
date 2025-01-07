/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:14:33 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/07 17:14:22 by dferjul          ###   ########.fr       */
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

// template<typename T>
class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;
	public:
		//	constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		//	methods
		void loadDatabase(const std::string &fileName);
		void loadInputFile(const std::string &fileName);
		double stringToDouble(const std::string &str);
		// parse
		// void parseDate()
		bool parseNumbersBtc(double Numbers);
};
