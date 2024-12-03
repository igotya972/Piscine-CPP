/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:13:22 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/03 01:34:52 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) 
{
	return *this;
}

void ScalarConverter::Convert(const std::string input)
{
	if (input.empty())
	{
		std::cout << "Error: Invalid input" << std::endl;
		return;
	}
	try
	{
		if (input.length() == 1 && std::isprint(input[0]))
		{
			if (!std::isdigit(input[0]))
			{
				char c = input[0];
				std::cout << "char: '" << c << "'" << std::endl;
				std::cout << "int: " << static_cast<int>(c) << std::endl;
				std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
				std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
				return;
			}
		}
		if (input == "nan" || input == "nanf" || input == "-inff" || input == "+inff" || 
			input == "-inf" || input == "+inf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << std::strtof(input.c_str(), NULL) << "f" << std::endl;
			std::cout << "double: " << std::strtod(input.c_str(), NULL) << std::endl;
			return;
		}
		int intNb = std::atoi(input.c_str());
		float floatNb = std::strtof(input.c_str(), NULL);
		double doubleNb = std::strtod(input.c_str(), NULL);

		if (intNb < 32 || intNb > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(intNb) << "'" << std::endl;
		std::cout << "int: " << intNb << std::endl;
		if (floatNb - intNb == 0)
			std::cout << "float: " << floatNb << ".0f" << std::endl;
		else
			std::cout << "float: " << floatNb << "f" << std::endl;
		if (doubleNb - intNb == 0)
			std::cout << "double: " << doubleNb << ".0" << std::endl;
		else
			std::cout << "double: " << doubleNb << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: Invalid input" << std::endl;
	}
}
