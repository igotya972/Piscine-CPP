/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:47:28 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/22 15:01:40 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat boss("Bob", 3);
		std::cout << boss << std::endl;

		std::cout << std::endl;
		ShrubberyCreationForm shrubbery("Marley");
		std::cout << shrubbery << std::endl;
		
		std::cout << std::endl;
		
		RobotomyRequestForm robot("Lucie");
		std::cout << robot << std::endl;

		std::cout << std::endl;

		PresidentialPardonForm pp("Maxime");
		std::cout << pp << std::endl;
		
		std::cout << std::endl;

		boss.signForm(shrubbery);
		boss.executeForm(shrubbery);
		
		std::cout << std::endl;
		
		//boss.signForm(robot);
		boss.executeForm(robot);
		
		std::cout << std::endl;
		
		boss.signForm(pp);
		boss.executeForm(pp);
		
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}