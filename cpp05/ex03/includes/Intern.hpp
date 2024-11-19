/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:22:34 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/19 15:26:26 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern : public AForm
{
	public :
		Intern();
		virtual ~Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& copy);
		AForm* makeForm(std::string name, std::string target);
		class FormNotFoundException : public std::exception
		{
			public:
				const char* what() const throw();
		};
}