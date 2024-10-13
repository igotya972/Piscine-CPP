/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:39:35 by dferjul           #+#    #+#             */
/*   Updated: 2024/10/13 01:58:31 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Animal.hpp"
#include "includes/Cat.hpp"
#include "includes/Dog.hpp"
#include "includes/Brain.hpp"

/* int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	

	delete j;
	delete i;
	delete meta;
	return 0;
} */

/* int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	for (int i = -1; i < 100; i++)
	{
		
	}
	delete j;
	delete i;
	return 0;
} */

int main(void)
{
    int     size = 10;
    Animal  *farm[size];
    int     i = 0;
    
    while(i < 5)
    {
        farm[i] = new Dog();
        i++;
    }
    while(i < size)
    {
        farm[i] = new Cat();
        i++;
    }
    std::cout << std::endl;
    i = 0;
    while (i < size)
    {
        farm[i]->makeSound();
        i++;
    }
    std::cout << std::endl;
    i = 0;
    while (i < size)
    {
        delete farm[i];
        i++;
    }
    return (0);
}