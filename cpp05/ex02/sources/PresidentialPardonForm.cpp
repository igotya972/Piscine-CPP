/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:38:11 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/08 16:50:27 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	*this = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	AForm::operator=(copy);
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
