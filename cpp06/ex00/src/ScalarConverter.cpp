/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:13:22 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/26 02:25:26 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void Convert(std::string &input)
{
	int convNbr;
	std::string str;
	double convDouble;
	
	if (input.empty())
	{
		std::cerr << "" << std::endl;
	}
}