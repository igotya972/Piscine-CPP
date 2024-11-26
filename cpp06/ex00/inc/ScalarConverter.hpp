/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:11:53 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/26 02:15:27 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

class ScalarConverter
{
private:
	/* data */
	ScalarConverter(/* args */);
	~ScalarConverter();
	// static void convertChar(std::string &input);
	// static void convertInt(std::string &input);
	// static void convertFloat(std::string &input);
	// static void convertDouble(std::string &input);
public:
	static void Convert(std::string input);
};
