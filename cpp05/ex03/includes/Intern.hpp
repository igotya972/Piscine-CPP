/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:22:34 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/20 18:22:59 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& copy);
		AForm* makeForm(std::string name, std::string target);
		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Form not found";
				}
		};
};