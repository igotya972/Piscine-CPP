/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:43:08 by dferjul           #+#    #+#             */
/*   Updated: 2024/10/12 22:55:09 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::ostringstream oss;
	for (int i = 0; i < 100; i++)
	{
		oss.str("");
		oss << "Idea " << i;
		_ideas[i] = oss.str();
	}
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	*this = copy;
}

Brain& Brain::operator=(const Brain& copy)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	return *this;
}
