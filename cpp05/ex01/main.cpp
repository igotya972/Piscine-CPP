/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:47:28 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/13 16:47:39 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Form.hpp"
#include "includes/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("b1", 1);
		std::cout << b1 << std::endl;
		Form formA("formA", 6, 42);
		std::cout << formA << std::endl;
		formA.signForm(b1);
		//std::cout << formA << std::endl;
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
