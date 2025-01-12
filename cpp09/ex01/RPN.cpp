/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:39:40 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/11 01:39:40 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy) : _stack(copy._stack) {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
		_stack = copy._stack;
	return *this;
}

bool RPN::isOperator(char c)
{
	return (c == '-' || c == '+' || c == '/' || c == '*');
}

bool RPN::isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

int RPN::calculate(int a, int b, char op)
{
	switch (op)
	{
	case '+' : return (a + b);
	case '-' : return (a - b);
	case '*' : return (a * b);
	case '/' : 
		if (a == 0 || b == 0)
			throw std::runtime_error("Error: division by zero");
		return (a / b);
	default:
		throw std::runtime_error("Error: invalid operator");
	}
}

int RPN::evaluate(std::string input)
{
	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
	{
		if (token.size() != 1)
			throw std::runtime_error("Error: Invalide token");
		if (isDigit(token[0]))
		{
			_stack.push(token[0] - '0');
		}
		else if (isOperator(token[0]))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: insufficient operands");

			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();
			_stack.push(calculate(a, b, token[0]));
		}
		else
			throw std::runtime_error("Error: invalid character");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: invalid input");
	return (_stack.top());
}