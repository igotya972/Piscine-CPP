/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:42:27 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/03 04:07:15 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Serializer.hpp"
#include <cassert>

int main ()
{
	 Data* originalData = new Data("test", 42);
	
	std::cout << "Original - Address: " << originalData << std::endl;
	std::cout << "Original - Name: " << originalData->_name << std::endl;
	std::cout << "Original - Value: " << originalData->_value << std::endl;

	uintptr_t serialized = Serializer::serialize(originalData);
	std::cout << "\nSerialized value: " << serialized << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "\nDeserialized - Address: " << deserialized << std::endl;
	std::cout << "Deserialized - Name: " << deserialized->_name << std::endl;
	std::cout << "Deserialized - Value: " << deserialized->_value << std::endl;	

	delete originalData;
	
	return 0;
}
