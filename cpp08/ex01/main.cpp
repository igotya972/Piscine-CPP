/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 06:39:31 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/08 04:21:04 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		std::cout << "\n---------------------------Test-Base-----------------------------" << std::endl;
		Span sp = Span(5);
		sp.addNumber(0);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(42);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
		std::cout << "\n---------------------------Test-Add-Range-----------------------------" << std::endl;
		Span randomSpan(10000);
		std::vector<int> randomNum;
		srand(time(NULL));
		for (int i = 0; i < 10; i++)
		{
			randomNum.push_back(rand() % 10000);
		}
		randomSpan.addRange(randomNum);
		std::cout << "shortestSpan: " << randomSpan.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << randomSpan.longestSpan() << std::endl;
		std::cout << "\n---------------------------Test-Error-----------------------------" << std::endl;
		Span smallSpan(5);
		std::vector<int> tooManySpan(10, 42);  // 10 éléments
		smallSpan.addRange(tooManySpan);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
