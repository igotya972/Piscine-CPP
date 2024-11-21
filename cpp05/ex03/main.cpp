/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:47:28 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/21 19:08:42 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Intern.hpp"

int main()
{
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat stagiaire("Stagiaire", 50);
		Intern someRandomIntern;

		std::cout << "=== Test de création de formulaires ===" << std::endl;
		
		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Bill");
		AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Jardin");
		
		std::cout << "\n=== Test d'exécution des formulaires ===" << std::endl;
		
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		
		boss.signForm(*scf);
		boss.executeForm(*scf);
		
		std::cout << "\n=== Test avec le stagiaire ===" << std::endl;
		stagiaire.signForm(*rrf);
		stagiaire.executeForm(*rrf);
		
		std::cout << "\n=== Test avec un formulaire invalide ===" << std::endl;
		try
		{
			AForm* form = someRandomIntern.makeForm("formulaire invalide", "Target");
			delete form;
		}
		catch (std::exception& e) {
			std::cout << "Exception lors de la création du formulaire : " << e.what() << std::endl;
		}
		
		delete rrf;
		delete ppf;
		delete scf;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception principale : " << e.what() << std::endl;
	}
	return 0;
}
