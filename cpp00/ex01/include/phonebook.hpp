/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 03:15:54 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/09 17:17:54 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook
{
	private:
		Contact contacts[8];
		int nb_contacts;
		void display_contact(int index);

	public:
		Phonebook();
		~Phonebook();
		void add_contact();
		void search_contact();
		void display_contacts();
};

#endif