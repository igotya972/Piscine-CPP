/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:53:16 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/12 19:53:16 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"


bool is_alpha(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		char c = input[i];
		if (!std::isalpha(c))
			return (false);
	}
	return (true);
}

bool is_all_digits(std::string phone_number)
{
	for (size_t i = 0; i < phone_number.length(); ++i)
	{
		if (std::isdigit(phone_number[i]))
		{
			continue;
		}
		else if (!std::isdigit(phone_number[i]))
		{
			std::cout << RED << "Invalid input: only digits allowed. Try again: " << RESET << std::endl;
			return (false);
		}
	}
	return (true);
}

bool is_valid_input(std::string input)
{
	if (input.find_first_of(" \t") != std::string::npos)
	{
		std::cout << RED << "Invalid input: no spaces or tabs allowed. Try again: " << RESET << std::endl;
		return (false);
	}
	if (!is_alpha(input))
	{
		std::cout << RED << "Invalid input: only alphabetic characters allowed. Try again: " << RESET << std::endl;
		return (false);
	}
	return (true);
}


