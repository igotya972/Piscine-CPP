/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 03:18:00 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/04 03:25:48 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "easyfind.hpp"

int main(int, char **) 
{
	std::vector<int> vec;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		const int value = rand() % 10;
		vec.push_back(value);
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 5);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	return 0;
}
