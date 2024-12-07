/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 06:39:16 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/08 00:13:31 by dferjul          ###   ########.fr       */
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
		throw std::exception();
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
		throw std::exception();
	std::vector<int> temp = _numbers;
	unsigned int N;
	std::sort(temp.begin(), temp.end());
	N = temp[_maxSize - 1] - temp[0];
	std::cout << "longest : " << N <<std::endl;
	return (N);
}
unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::exception();
	std::vector<int> temp = _numbers;
	int result;
	std::sort(temp.begin(), temp.end());
	result = temp[1] - temp[0];
	for (unsigned int i = 1; i < _maxSize - 1; i++)
	{
		if (result > temp[i + 1] - temp[i])
			result = temp[i + 1] - temp[i];
	}
	std::cout << "shortest : " << result << std::endl;
	return result;
}

void Span::addRange(std::vector<int> addList)
{
	if (_numbers.size() >= _maxSize)
		throw std::exception();
	_numbers.insert(_numbers.end(), addList.begin(), addList.end());
}