/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:30:10 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/23 04:38:13 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sys/time.h>
#include <utility>  // pour std::pair
#include <cstdlib>
#include <sstream>
#include <climits>
#include <vector>
#include <deque>

class PmergeMe
{
private:
	std::vector<int> numbersVec;
	std::deque<int> numbersDeque;
	double timeVector;
	double timeDeque;

public:
	void fordJohnsonSortVec(std::vector<int>& vec);
	std::vector<int> generateJacobsthalSequenceVec(int n);
	void fordJohnsonSortDeque(std::deque<int>& vec);
	std::deque<int> generateJacobsthalSequenceDeque(int n);
	
	double getCurrentTime() const;
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);
	~PmergeMe();

	void addNumber(int n);
	void sort();
	void display() const;
	void displayTime() const;
};
