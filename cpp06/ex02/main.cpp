/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:46:27 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/03 17:49:08 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Base.hpp"

int main ()
{
	Base *Welcome = generate();
	std::cout << "Adresse: " << Welcome << std::endl;
	std::cout << "Pointer: ";
	identify(Welcome);
	std::cout << "Reference: ";
	identify(*Welcome);
	delete Welcome;
	return 0;
}
