/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:03:37 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/13 19:56:47 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

Contact::Contact(){}
Contact::~Contact(){}

void Contact::set_first_name(std::string first_name)
{
	while (1)
	{
		std::cout << BLUE;
		std::cout << "Enter your first name: ";
		std::cout << RESET;
		std::getline(std::cin, first_name);
		if (std::cin.eof())
			return;
		if (!is_valid_input(first_name))
			continue;
		size_t start = first_name.find_first_not_of(" \t\n");
		size_t end = first_name.find_last_not_of(" \t\n");
		if (start == std::string::npos)
		{
			std::cout << RED;
			std::cout << "Invalid input. (is empty) Try again: " << std::endl;
			std::cout << RESET;
		}
		else if (end - start + 1 < 2)
		{
			std::cout << RED;
			std::cout << "Invalid input: minimum 2 characters required. Try again: " << std::endl;
			std::cout << RESET;
		}
		else
		{
			this->first_name = first_name;
			std::cout << GREEN;
			std::cout << "first name: " << this->first_name << std::endl;
			std::cout << RESET;
			break;
		}
	}
}

void Contact::set_nickname(std::string nickname)
{
	while (1)
	{
		std::cout << BLUE;
		std::cout << "Enter your nickname: ";
		std::cout << RESET;
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			return;
		size_t start = nickname.find_first_not_of(" \t\n");
		size_t end = nickname.find_last_not_of(" \t\n");
		if (!is_valid_input(nickname))
			continue;
		if (start == std::string::npos)
		{
			std::cout << RED;
			std::cout << "Invalid input. (is empty) Try again: " << std::endl;
			std::cout << RESET;
		}
		else if (end - start + 1 < 2)
		{
			std::cout << RED;
			std::cout << "Invalid input: minimum 2 characters required. Try again: " << std::endl;
			std::cout << RESET;
		}
		else
		{
			this->nickname = nickname;
			std::cout << GREEN;
			std::cout << "nickname: " << this->nickname << std::endl;
			std::cout << RESET;
			break;
		}
	}
}

void Contact::set_last_name(std::string last_name)
{
	while (1)
	{
		std::cout << BLUE;
		std::cout << "Enter your last_name: ";
		std::cout << RESET;
		std::getline(std::cin, last_name);
		if (std::cin.eof())
			return;
		if (!is_valid_input(last_name))
			continue;
		size_t start = last_name.find_first_not_of(" \t\n");
		size_t end = last_name.find_last_not_of(" \t\n");
		if (start == std::string::npos)
		{
			std::cout << RED;
			std::cout << "Invalid input. (is empty) Try again: " << std::endl;
			std::cout << RESET;
		}
		else if (end - start + 1 < 2)
		{
			std::cout << RED;
			std::cout << "Invalid input: minimum 2 characters required. Try again: " << std::endl;
			std::cout << RESET;
		}
		else
		{
			this->last_name = last_name.substr(start, end - start + 1);
			std::cout << GREEN;
			std::cout << "last_name: " << this->last_name << std::endl;
			std::cout << RESET;
			break;
		}
	}
}

void Contact::set_phone_number(std::string phone_number)
{
	while (1)
	{
		std::cout << BLUE;
		std::cout << "Enter your Number: ";
		std::cout << RESET;
		if(std::cin.eof())
			break;
		std::getline(std::cin, phone_number);
		if (!is_all_digits(phone_number))
			continue;
		if (phone_number.empty())
		{
			std::cout << RED;
			std::cout << "The phone number cannot be empty. Try again." << std::endl;
			std::cout << RESET;
		}
		else
		{
			this->phone_number = phone_number;
			std::cout << GREEN;
			std::cout << "Number: " << this->phone_number << std::endl;
			std::cout << RESET;
				break;
		}	
	}
}

void Contact::set_darkest_secret(std::string darkest_secret)
{
	while (1)
	{
		if (darkest_secret.empty())
		{
			std::cout << BLUE;
			std::cout << "Enter your darkest_secret: ";
			std::cout << RESET;
			if (std::cin.eof())
				break;
			std::getline(std::cin, darkest_secret);
		}
		else if (darkest_secret.length() < 8)
		{
			std::cout << RED;
			std::cout << "Invalid inputs: requires minimum 8 characters. Try again: " << std::endl;
			std::cout << RESET;
			darkest_secret.clear();
		}
		else
		{
			this->darkest_secret = darkest_secret;
			std::cout << GREEN;
			std::cout << "darkest_secret: ";
			std::cout << this->darkest_secret << std::endl;
			std::cout << RESET;
			break;
		}
	}
}

void Contact::display_contact()
{
	if (first_name.length() >= 9)
		std::cout << RED << std::setw(9) << first_name.erase(9) << RESET << BLUE << ". | ";
	else
		std::cout << RED << std::setw(10) << first_name << RESET << BLUE << " | ";
	if (last_name.length() >= 9)
		std::cout << RED << std::setw(9) << last_name.erase(9) << RESET << BLUE << ". | ";
	else
		std::cout << RED << std::setw(10) << last_name << RESET << BLUE << " | ";
	if (nickname.length() >= 9)
		std::cout << RED << std::setw(9) << nickname.erase(9) << RESET << BLUE << ". | " << std::endl;
	else
		std::cout << RED << std::setw(10) << nickname << RESET << BLUE << " | " << std::endl;
}

std::string Contact::get_first_name() {
	return first_name;
}
std::string Contact::get_last_name() {
	return last_name;
}
std::string Contact::get_nickname() {
	return nickname;
}
std::string Contact::get_phone_number() {
	return phone_number;
}
std::string Contact::get_darkest_secret() {
	return darkest_secret;
}