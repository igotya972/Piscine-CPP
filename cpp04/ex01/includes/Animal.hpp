/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorphisme.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:01:58 by dferjul           #+#    #+#             */
/*   Updated: 2024/09/26 21:01:58 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& copy);
		virtual ~Animal();
		std::string getType() const;
		virtual void makeSound() const;
		Animal& operator=(const Animal& copy);
};

