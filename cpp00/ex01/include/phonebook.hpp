/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 03:15:54 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/10 20:41:35 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook
{
	private:
		Contact contacts[9];
		int nb_contacts;
		void display_contact(int index);

	public:
		Phonebook();
		~Phonebook();
		void add_contact();
		void search_contact();
		void display_contacts();
		void display_tab();
};

#endif