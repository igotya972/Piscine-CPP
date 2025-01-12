/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:39:58 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/11 01:39:58 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
private:
	std::stack<int> _stack;
public:
	RPN();
	RPN(const RPN &copy);
	~RPN();
	RPN &operator=(const RPN &copy);
	bool isOperator(char c);
	bool isDigit(char c);
	int calculate(int a, int b, char op);
	int evaluate(std::string input);
};

