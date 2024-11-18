/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:47:28 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/16 05:59:20 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat *boss = new Bureaucrat("Bob", 3);
	std::cout << *boss << std::endl;

	std::cout << std::endl;
	
	try {
		AForm *shrubbery = new ShrubberyCreationForm("Marley");
		std::cout << *shrubbery << std::endl;
		
		std::cout << std::endl;
		
		AForm *robot = new RobotomyRequestForm("Lucie");
		std::cout << *robot << std::endl;

		std::cout << std::endl;

		AForm *pp = new PresidentialPardonForm("Maxime");
		std::cout << *pp << std::endl;
		
		std::cout << std::endl;

		boss->signForm(*shrubbery);
		boss->executeForm(*shrubbery);
		
		std::cout << std::endl;
		
		boss->signForm(*robot);
		boss->executeForm(*robot);
		
		std::cout << std::endl;
		
		boss->signForm(*pp);
		boss->executeForm(*pp);
		
		std::cout << std::endl;
		
		delete (shrubbery);
		delete (robot);
		delete (pp);
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cerr << "\033[33mERROR: " << e.what() << std::endl << "\033[0m" << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << "\033[33mERROR: " << e.what() << std::endl << "\033[0m" << std::endl;
	}
	delete (boss);
	
}