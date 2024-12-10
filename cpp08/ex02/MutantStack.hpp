/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:48:24 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/10 12:25:41 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack &copy);
	MutantStack &operator=(const MutantStack &copy)
	{
		if (this != &copy)
			//
		return (*this);
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};