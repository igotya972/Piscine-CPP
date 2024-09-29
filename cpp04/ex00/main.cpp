/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:59:44 by dferjul           #+#    #+#             */
/*   Updated: 2024/09/26 20:59:44 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"

/* int main()
{
	//const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	//meta->makeSound();
	//delete meta;
	delete j;
	delete i;
	return 0;
} */

int main()
{
	//const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	//std::cout << meta->getType() << " " << std::endl;
	//std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	//meta->makeSound();
	//delete meta;
	delete i;
	return 0;
}

