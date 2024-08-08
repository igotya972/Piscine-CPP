/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:25:33 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/08 22:01:35 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

	#include "../include/phonebook.hpp"
#endif
int main ()
{
	//Phonebook phonebook;
	Contact		contact;
	std::string first_name;
	std::string phone_number;
	std::string nickname;
	std::string darkest_secret;
	
	contact.set_first_name(first_name);
	contact.set_phone_number(phone_number);
	contact.set_nickname(nickname);
	contact.set_darkest_secret(darkest_secret);
	return (0);
}