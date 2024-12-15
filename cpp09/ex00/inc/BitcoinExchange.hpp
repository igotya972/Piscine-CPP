/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:14:33 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/15 01:11:35 by dferjul          ###   ########.fr       */
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

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;
	public:	
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		void loadDatabase(const std::string &fileName);
		void loadInputFile(const std::string &fileName);
		// double getExchange(const std::string &date);
};