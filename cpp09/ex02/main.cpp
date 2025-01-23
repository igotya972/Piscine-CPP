/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:14:59 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/23 04:52:41 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: Usage: " << av[0] << " <sequence of positive integers>" << std::endl;
		return 1;
	}

	// Créer l'objet sur le tas plutôt que sur la pile
	PmergeMe *sorter = new PmergeMe();
	
	try 
	{
		// Parsing et validation des arguments
		for (int i = 1; i < ac; ++i)
		{
			std::istringstream iss(av[i]);
			int num;
			
			if (!(iss >> num) || num < 0 || iss.rdbuf()->in_avail() != 0)
			{
				delete sorter;
				std::cerr << "Error: Invalid argument: " << av[i] << std::endl;
				return 1;
			}
			sorter->addNumber(num);
		}

		// Affichage et tri
		sorter->display();
		sorter->sort();
		sorter->display();
		
		delete sorter;
	}
	catch (const std::runtime_error& e)
	{
		delete sorter;
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

