/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:03:37 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/06 17:30:08 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

void Contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}
