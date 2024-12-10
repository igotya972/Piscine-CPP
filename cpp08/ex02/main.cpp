/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 03:18:00 by dferjul           #+#    #+#             */
/*   Updated: 2024/12/10 12:24:41 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <stack>

int main(int, char **) 
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\nTest with list base ===========" << std::endl;
	std::list<int> ltstack;
	ltstack.push_back(5);
	ltstack.push_back(17);
	std::cout << ltstack.back() << std::endl;
	ltstack.pop_back();
	std::cout << ltstack.size() << std::endl;
	ltstack.push_back(3);
	ltstack.push_back(5);
	ltstack.push_back(737);
	//[...]
	ltstack.push_back(0);
	std::list<int>::iterator itNew = ltstack.begin();
	std::list<int>::iterator iteNew = ltstack.end();
	while (itNew != iteNew)
	{
		std::cout << *itNew << std::endl;
		++itNew;
	}
	//std::stack<int> s(mstack);
	
	
	return 0;
}


