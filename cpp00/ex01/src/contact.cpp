/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:03:37 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/08 22:18:57 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

void Contact::set_first_name(std::string first_name)
{
	while (1)
	{
		std::cout << "Enter your first name: ";
		std::getline(std::cin, first_name);
		size_t start = first_name.find_first_not_of(" \t\n");
		size_t end = first_name.find_last_not_of("\t\n");
		if (start == std::string::npos)
			std::cout << "Invalid input. (is empty) Try again: " << std::endl;
		else if (end - start + 1 < 2)
			std::cout << "Invalid input: minimum 2 characters required. Try again: " << std::endl;
		else
		{
			this->first_name = first_name;
			std::cout << "first name: " << this->first_name << std::endl;
			break;
		}
	}
}

void Contact::set_phone_number(std::string phone_number)
{
	this->phone_number = phone_number;
	while (1)
	{
		if (phone_number.empty())
		{
			std::cout << "Enter your Number: ";
			std::cin >> phone_number;
		}
		else if ((phone_number[1] != '6' && phone_number[1] != '7') || phone_number[0] != '0' || phone_number[10] || !phone_number[9])
		{
			std::cout << "Invalid phone number (ex: 06********, 07********). Try again: " << std::endl;
			std::cout << "Enter your Number: ";
			std::cin >> phone_number;
		}
		else
		{
			for (int i = 0; phone_number[i], i++;)
			{
				if (std::isdigit(phone_number[i]) != 0)
				{
					std::cout << "Invalid input. Character is not numeric. Try again: " << std::endl;
					std::cout << "Enter your Number: ";
					std::cin >> phone_number;
				}
			}
			std::cout << "Number: ";
			std::cout << phone_number << std::endl;
			break;
		}
	}
}

void Contact::set_nickname(std::string nickname)
{
	while (1)
	{
		std::cout << "Enter your nickname: ";
		std::getline(std::cin, nickname);
		size_t start = nickname.find_first_not_of(" \t\n");
		size_t end = nickname.find_last_not_of("\t\n");
		if (start == std::string::npos)
			std::cout << "Invalid input. (is empty) Try again: " << std::endl;
		else if (end - start + 1 < 2)
			std::cout << "Invalid input: minimum 2 characters required. Try again: " << std::endl;
		else
		{
			this->nickname = nickname;
			std::cout << "nickname: " << this->nickname << std::endl;
			break;
		}
	}
}

void Contact::set_last_name(std::string last_name)
{
	while (1)
	{
		std::cout << "Enter your last_name: ";
		std::getline(std::cin, last_name);
		size_t start = last_name.find_first_not_of(" \t\n");
		size_t end = last_name.find_last_not_of("\t\n");
		if (start == std::string::npos)
			std::cout << "Invalid input. (is empty) Try again: " << std::endl;
		else if (end - start + 1 < 2)
			std::cout << "Invalid input: minimum 2 characters required. Try again: " << std::endl;
		else
		{
			this->last_name = last_name;
			std::cout << "last_name: " << this->last_name << std::endl;
			break;
		}
	}
}

void Contact::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
	while (1)
	{
		if (darkest_secret.empty())
		{
			std::cout << "Enter your darkest_secret: ";
			std::getline(std::cin, darkest_secret);
		}
		if (!darkest_secret[7])
		{
			std::cout << "Invalid darkest_secret: requires minimum 8 characters. Try again: " << std::endl;
			std::cout << "Enter your darkest_secret: ";
			std::getline(std::cin, darkest_secret);
		}
		else
		{
			std::cout << "darkest_secret: ";
			std::cout << darkest_secret << std::endl;
			break;
		}
	}
}