/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 03:15:54 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/12 20:00:50 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "contact.hpp"

class Phonebook
{
	private:
		Contact contacts[9];
		int nb_contacts;

	public:
		Phonebook();
		~Phonebook();
		void add_contact();
		void search_contact();
		void display_tab();
};
