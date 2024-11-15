/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:47:28 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/15 01:04:49 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Form.hpp"
#include "includes/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("b1", 7);
		std::cout << b1 << std::endl;
		Form formA("formA", 6, 42);
		std::cout << formA << std::endl;
		b1.signForm(formA);
		b1.upGrade();
		std::cout << b1 << std::endl;
		b1.signForm(formA);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	try
	{
		
		Bureaucrat b2("b2", 150);
		std::cout << b2 << std::endl;
		b2.upGrade();
		std::cout << b2 << std::endl;
		b2.downGrade();
		std::cout << b2 << std::endl;
		b2.downGrade();
		std::cout << b2 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
