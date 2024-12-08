/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 06:39:22 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/08 03:58:00 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>

class Span
{
private:
	std::vector<int>	_numbers;
	unsigned int		_maxSize;
public:
	Span(unsigned int n);;
	~Span();
	Span(const Span &copy);
	Span &operator=(const Span &copy);

	void addNumber(int number);
	unsigned int longestSpan() const;
	unsigned int shortestSpan() const;

	void addRange(std::vector<int> addList);
	class NoSpanException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Error: cannot calculate span with less than 2 numbers";
			}
	};
	class LimitSpanException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
            	return "Error: Span is full";
        	}
	};
};

