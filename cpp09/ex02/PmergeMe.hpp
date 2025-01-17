/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:30:10 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/17 01:01:48 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sys/time.h>
#include <utility>  // pour std::pair
#include <cstdlib>
#include <sstream>

class PmergeMe
{
private:
	std::list<int> numbers;
	std::vector<int> numbersVec;
	double timeList;
	double timeVector;

	void fordJohnsonSort(std::list<int>& lst);
	void fordJohnsonSortVec(std::vector<int>& vec);
	std::vector<int> generateJacobsthalSequence(int n);
	
	double getCurrentTime() const;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);
	~PmergeMe();

	void addNumber(int n);
	void sort();
	void display() const;
	void displayTime() const;
};
