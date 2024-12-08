/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 06:39:16 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/08 04:03:06 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int numbers) :  _maxSize(numbers){
	_numbers.reserve(numbers);
}

Span::~Span() {}

Span::Span(const Span &copy) : _numbers(copy._numbers), _maxSize(copy._maxSize) {}

Span &Span::operator=(const Span &copy) {
	if  (this != &copy)
	{
		this->_maxSize = copy._maxSize;
		this->_numbers = copy._numbers;
	}
	return (*this);
}

void Span::addNumber(int numbers)
{
	if (_numbers.size() >= _maxSize)
		throw LimitSpanException();
	//std::cout << "max size : " << _maxSize << std::endl;
	//for (unsigned int i = 0; i < (_maxSize); i++)
	//{
		_numbers.push_back(numbers); 
		//std::cout << _numbers[0] << std::endl;
//	}
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	std::vector<int> temp = _numbers;
	unsigned int N;
	std::sort(temp.begin(), temp.end());
	N = temp[temp.size() - 1] - temp[0];
	return (N);
}
unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	std::vector<int> temp = _numbers;
	std::sort(temp.begin(), temp.end());
	
	int result = (temp[1] - temp[0]);
	for (unsigned int i = 1; i < temp.size() - 1; i++)
	{
		if (result > temp[i + 1] - temp[i])
			result = temp[i + 1] - temp[i];
	}
	return result;
}

void Span::addRange(std::vector<int> addList)
{
	if (_numbers.size() + addList.size() > _maxSize)
		throw LimitSpanException();
	_numbers.insert(_numbers.end(), addList.begin(), addList.end());
}