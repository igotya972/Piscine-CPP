/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:41:05 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/23 05:41:56 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : numbersVec(), numbersDeque(), timeVector(0), timeDeque(0) {}

PmergeMe::PmergeMe(const PmergeMe &copy) 
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		this->numbersVec = copy.numbersVec;
		this->numbersDeque = copy.numbersDeque;
		this->timeVector = copy.timeVector;
		this->timeDeque = copy.timeDeque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}


double PmergeMe::getCurrentTime() const
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec) / 1000.0;
}

void PmergeMe::addNumber(int n)
{
	if (std::find(numbersVec.begin(), numbersVec.end(), n) != numbersVec.end())
	{
		throw std::runtime_error("Error: duplicate numbers are not allowed");
	}
	numbersVec.push_back(n);
	numbersDeque.push_back(n);
}

void PmergeMe::display() const
{
	static bool firstCall = true;
	const size_t maxDisplay = 5;

	if (firstCall)
	{
		std::cout << "Before: ";
		size_t count = 0;
		for (std::vector<int>::const_iterator it = numbersVec.begin(); 
			 it != numbersVec.end() && count < maxDisplay; ++it, ++count)
		{
			std::cout << *it << " ";
		}
		if (numbersVec.size() > maxDisplay)
			std::cout << "[...]";
		firstCall = false;
	}
	else
	{
		std::cout << "After: ";
		size_t count = 0;
		for (std::vector<int>::const_iterator it = numbersVec.begin(); 
			 it != numbersVec.end() && count < maxDisplay; ++it, ++count)
		{
			std::cout << *it << " ";
		}
		if (numbersVec.size() > maxDisplay)
			std::cout << "[...]";
		std::cout << std::endl;
		displayTime();
	}
}

void PmergeMe::displayTime() const
{
	std::cout << "Time to process a range of " << numbersVec.size() 
			  << " elements with std::vector : " << std::fixed << std::setprecision(5) 
			  << timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << numbersDeque.size() 
			  << " elements with std::deque : " << std::fixed << std::setprecision(5) 
			  << timeDeque << " us" << std::endl;
}

void PmergeMe::sort()
{
	if (numbersVec.empty())
		return;
	
	// vector
	double startVec = getCurrentTime();
	fordJohnsonSortVec(numbersVec);
	double endVec = getCurrentTime();
	timeVector = endVec - startVec;
	
	// deque
	double startDeque = getCurrentTime();
	fordJohnsonSortDeque(numbersDeque);
	double endDeque = getCurrentTime();
	timeDeque = endDeque - startDeque;
}

// ..........................................................Parti Vectors..........................................................

std::vector<int> PmergeMe::generateJacobsthalSequenceVec(int n)
{
	std::vector<int> jacobsthal;
	jacobsthal.push_back(3);
	
	int prev2 = 1;
	int prev1 = 3;
	
	while (prev1 < n)
	{
		int next = prev1 + 2 * prev2;
		// if (next >= n)
		// 	break;
		jacobsthal.push_back(next);
		prev2 = prev1;
		prev1 = next;
	}
	return jacobsthal;
}


void PmergeMe::fordJohnsonSortVec(std::vector<int>& vec)
{
	if (vec.size() <= 1) return;

	std::vector<std::pair<int, int> > pairs;
	size_t i;
	for (i = 0; i < vec.size() - 1; i += 2)
	{
		int a = vec[i], b = vec[i + 1];
		pairs.push_back(std::make_pair(a, b));
	}
	int straggler = -1;
	if (i < vec.size())
		straggler = vec[i];

	std::vector<std::pair<int, int> > sortedPairs;
	for (size_t j = 0; j < pairs.size(); ++j)
	{
		if (pairs[j].first > pairs[j].second)
			sortedPairs.push_back(pairs[j]);
		else
			sortedPairs.push_back(std::make_pair(pairs[j].second, pairs[j].first));
	}
	
	for (size_t i = 0; i < sortedPairs.size(); ++i)
	{
		for (size_t j = 0; j < sortedPairs.size() - 1; ++j)
		{
			if (sortedPairs[j].first > sortedPairs[j + 1].first)
			{
				std::pair<int, int> temp = sortedPairs[j];
				sortedPairs[j] = sortedPairs[j + 1];
				sortedPairs[j + 1] = temp;
			}
		}
	}

	vec.clear();
	for (size_t j = 0; j < sortedPairs.size(); ++j)
		vec.push_back(sortedPairs[j].first);
	std::vector<int> pend;
	for (size_t j = 0; j < sortedPairs.size(); ++j)
		pend.push_back(sortedPairs[j].second);
	if (!pend.empty())
	{
		vec.insert(vec.begin(), pend[0]);
	}

	std::vector<int> insertionOrder;
	std::vector<int> jacobsthalVec = generateJacobsthalSequenceVec(pend.size());
	
	std::vector<bool> processed(pend.size(), false);
	for (size_t i = 0; i < jacobsthalVec.size() && insertionOrder.size() < pend.size(); i++)
	{
		if (jacobsthalVec[i] < static_cast<int>(pend.size()))
		{
			insertionOrder.push_back(jacobsthalVec[i]);
		}
		int lowerBound;
		if (i > 0)
			lowerBound = jacobsthalVec[i-1];
		else
			lowerBound = -1;
		for (int j = jacobsthalVec[i] - 1; j > lowerBound && j >= 1; --j)
		{
			if (j < static_cast<int>(pend.size()) && !processed[j])
			{
				insertionOrder.push_back(j);
				processed[j] = true;
			}
		}		
	}

	std::vector<bool> inserted(pend.size(), false);
	inserted[0] = true;
	for (size_t j = 0; j < insertionOrder.size(); ++j)
	{
		int idx = insertionOrder[j];
		if (idx > 0 && idx < static_cast<int>(pend.size()) && !inserted[idx])
		{
			std::vector<int>::iterator pos = std::lower_bound(vec.begin(), vec.end(), pend[idx]);
			vec.insert(pos, pend[idx]);
			inserted[idx] = true;
		}
	}
	if (straggler != -1)
	{
		std::vector<int>::iterator pos = 
			std::lower_bound(vec.begin(), vec.end(), straggler);
		vec.insert(pos, straggler);
	}
}

// ..........................................................Parti Deque..........................................................

std::deque<int> PmergeMe::generateJacobsthalSequenceDeque(int n)
{
	std::deque<int> jacobsthal;
	jacobsthal.push_back(3);
	
	int prev2 = 1;
	int prev1 = 3;
	
	while (prev1 < n)
	{
		int next = prev1 + 2 * prev2;
		// if (next >= n)
		// 	break;
		jacobsthal.push_back(next);
		prev2 = prev1;
		prev1 = next;
	}
	return jacobsthal;
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& deq)
{
	if (deq.size() <= 1) return;

	std::deque<std::pair<int, int> > pairs;
	size_t i;
	for (i = 0; i < deq.size() - 1; i += 2)
	{
		int a = deq[i], b = deq[i + 1];
		pairs.push_back(std::make_pair(a, b));
	}
	int straggler = -1;
	if (i < deq.size())
		straggler = deq[i];

	std::deque<std::pair<int, int> > sortedPairs;
	for (size_t j = 0; j < pairs.size(); ++j)
	{
		if (pairs[j].first > pairs[j].second)
			sortedPairs.push_back(pairs[j]);
		else
			sortedPairs.push_back(std::make_pair(pairs[j].second, pairs[j].first));
	}
	std::cout << std::endl;
	
	for (size_t i = 0; i < sortedPairs.size(); ++i)
	{
		for (size_t j = 0; j < sortedPairs.size() - 1; ++j)
		{
			if (sortedPairs[j].first > sortedPairs[j + 1].first)
			{
				std::pair<int, int> temp = sortedPairs[j];
				sortedPairs[j] = sortedPairs[j + 1];
				sortedPairs[j + 1] = temp;
			}
		}
	}

	deq.clear();
	for (size_t j = 0; j < sortedPairs.size(); ++j)
		deq.push_back(sortedPairs[j].first);
	std::deque<int> pend;
	for (size_t j = 0; j < sortedPairs.size(); ++j)
		pend.push_back(sortedPairs[j].second);
	if (!pend.empty())
	{
		deq.insert(deq.begin(), pend[0]);
	}

	std::deque<int> insertionOrder;
	std::deque<int> jacobsthalDeq = generateJacobsthalSequenceDeque(pend.size());
	
	std::deque<bool> processed(pend.size(), false);
	for (size_t i = 0; i < jacobsthalDeq.size() && insertionOrder.size() < pend.size(); i++)
	{
		if (jacobsthalDeq[i] < static_cast<int>(pend.size()))
		{
			insertionOrder.push_back(jacobsthalDeq[i]);
		}
		int lowerBound;
		if (i > 0)
			lowerBound = jacobsthalDeq[i-1];
		else
			lowerBound = -1;
		for (int j = jacobsthalDeq[i] - 1; j > lowerBound && j >= 1; --j)
		{
			if (j < static_cast<int>(pend.size()) && !processed[j])
			{
				insertionOrder.push_back(j);
				processed[j] = true;
			}
		}		
	}

	std::deque<bool> inserted(pend.size(), false);
	inserted[0] = true;
	for (size_t j = 0; j < insertionOrder.size(); ++j)
	{
		int idx = insertionOrder[j];
		if (idx > 0 && idx < static_cast<int>(pend.size()) && !inserted[idx])
		{
			std::deque<int>::iterator pos = std::lower_bound(deq.begin(), deq.end(), pend[idx]);
			deq.insert(pos, pend[idx]);
			inserted[idx] = true;
		}
	}
	if (straggler != -1)
	{
		std::deque<int>::iterator pos = 
			std::lower_bound(deq.begin(), deq.end(), straggler);
		deq.insert(pos, straggler);
	}
}