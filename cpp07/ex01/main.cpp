/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:03:10 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/04 00:59:30 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void print(int const &a)
{
	std::cout << a << std::endl;
}

void print(std::string const &a)
{
	std::cout << a << std::endl;
}

int main( void ) 
{
	int a[] = {1, 2, 3, 4, 5};
	std::string b[] = {"un", "deux", "trois", "quatre", "cinq"};
	iter(a, 5, print);
	iter(b, 5, print);
	return 0;
}
