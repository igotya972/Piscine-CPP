/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:28:05 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/21 18:37:39 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::cout << "\033[1;35m*drilling noises*\033[0m" << std::endl;
	if (rand() % 2)
		std::cout << "\033[1;34m" << this->_target << " has been robotomized successfully\033[0m" << std::endl;
	else
		std::cout << "\033[1;34m" << this->_target << " robotomization failed\033[0m" << std::endl;
}
