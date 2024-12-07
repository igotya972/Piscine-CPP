/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 06:39:22 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/07 06:58:25 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Span
{
private:
	std::vector<int>	_numbers;
	unsigned int		_max_size;
public:
	Span(unsigned int n);;
	~Span();
	Span(const Span &copy);
	Span &operator=(const Span &copy);

	void addNumber(int number);
	unsigned int maxNumber() const;
	unsigned int minNumber() const;

	class NoSpanException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class LimitSpanException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

