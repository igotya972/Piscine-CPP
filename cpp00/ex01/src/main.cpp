/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:25:33 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/08 19:52:40 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

	#include "../include/phonebook.hpp"
#endif
int main (int ac, char **av)
{
	(void) ac;
	(void) av;
	//Phonebook phonebook;
	Contact		contact;
	//int			Ages;
	std::string first_name;
	std::string phone_number;
	
	// std::cout << "Enter your age: ";
	// std::cin >> Ages;
	contact.set_first_name(first_name);
	contact.set_phone_number(phone_number);
	return (0);
}