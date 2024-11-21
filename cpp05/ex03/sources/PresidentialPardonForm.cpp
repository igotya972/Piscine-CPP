/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:38:11 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/21 18:36:13 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << "\033[1;33m" << this->_target << " has been pardoned by Zafod Beeblebrox\033[0m" << std::endl;
}
