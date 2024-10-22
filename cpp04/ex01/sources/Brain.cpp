/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:51:29 by dferjul           #+#    #+#             */
/*   Updated: 2024/10/22 18:04:59 by dferjul          ###   ########.fr       */
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
	return (*this);
}

void Brain::setIdeas(int index, std::string idea)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}

std::string Brain::getIdeas(int index) const
{
	
	if (index >= 0 && index < 100)
		return (this->_ideas[index]);
	else
		return ("Index doesn't exist.");
}