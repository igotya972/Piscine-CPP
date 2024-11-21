/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:22:54 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/20 18:19:31 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& copy)
{
	(void)copy;
}

Intern& Intern::operator=(const Intern& copy)
{
	(void)copy;
	return (*this);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm *createForm = NULL;
	std::string FormsName[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int index = -1;
	for (int i = 0; i < 3; i++)
	{
		if (name == FormsName[i])
			index = i;
	}
	switch (index)
	{
		case 0:
			createForm = new RobotomyRequestForm(target);
			break;
		case 1:
			createForm = new PresidentialPardonForm(target);
			break;
		case 2:
			createForm = new ShrubberyCreationForm(target);
			break;
		default:
			throw FormNotFoundException();
	}
	std::cout << "Intern creates " << createForm->getName() << std::endl;
	return (createForm);
}