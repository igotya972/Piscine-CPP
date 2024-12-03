/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:46:27 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/03 13:02:03 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Base.hpp"

int main ()
{
	Base *b = generate();
	std::cout << "Pointer: ";
	identify_from_pointer(b);
	std::cout << "Reference: ";
	identify_from_reference(*b);
	delete b;
	return 0;
}
