/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:37:36 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/08 16:51:34 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{ 
private:
	const std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
	void execute(const Bureaucrat& executor) const;
};