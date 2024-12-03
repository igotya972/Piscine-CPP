/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:09:09 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/03 01:35:32 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ScalarConverter.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: invalid number of arguments" << std::endl;
		return 1;
	}
	// std::cout << "int: " << static_cast<int>(c[1]) << std::endl;
	ScalarConverter::Convert(av[1]);
	return 0;
}