/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:30:10 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/22 18:07:13 by dferjul          ###   ########.fr       */
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
#include <climits>

class PmergeMe
{
private:
	std::vector<int> numbersVec;
	double timeList;
	double timeVector;
public:
	void fordJohnsonSort(std::list<int>& lst);
	void fordJohnsonSortVec(std::vector<int>& vec);
	std::vector<int> generateJacobsthalSequenceVec(int n);
	
	double getCurrentTime() const;
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);
	~PmergeMe();

	void addNumber(int n);
	void sort();
	void display() const;
	void displayTime() const;
	bool parseArgs(int argc, char **argv);
};
