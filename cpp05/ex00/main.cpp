/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:47:28 by dferjul           #+#    #+#             */
/*   Updated: 2024/11/22 14:52:24 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("John", 15);
		std::cout << bureaucrat << std::endl;
		bureaucrat.downGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;
	try
	{
		Bureaucrat bureaucrat("U", 155);
		std::cout << bureaucrat << std::endl;
		bureaucrat.downGrade();
		bureaucrat.upGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
