/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:41:05 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/23 00:06:47 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) 
{
	// this->numbers = copy.numbers;
	this->numbersVec = copy.numbersVec;
	this->timeList = copy.timeList;
	this->timeVector = copy.timeVector;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		// this->numbers = copy.numbers;
		this->numbersVec = copy.numbersVec;
		this->timeList = copy.timeList;
		this->timeVector = copy.timeVector;
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

bool PmergeMe::parseArgs(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return false;
	}
	for (int i = 1; i < argc; ++i)
	{
		std::string str = argv[i];		
		// Vérification des caractères valides
		if (str.empty() || str.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cerr << "Error" << std::endl;
			return false;
		}
		// Conversion et vérification du nombre
		long num = std::atol(str.c_str());
		if (num <= 0 || num > INT_MAX)
		{
			std::cerr << "Error" << std::endl;
			return false;
		}
		// numbers.push_back(static_cast<int>(num));
		numbersVec.push_back(static_cast<int>(num));
	}
	return true;
}

void PmergeMe::addNumber(int n)
{
	// Vérifier les doublons dans le vector (plus rapide que la liste)
	if (std::find(numbersVec.begin(), numbersVec.end(), n) != numbersVec.end())
	{
		throw std::runtime_error("Error: duplicate numbers are not allowed");
	}
	// numbers.push_back(n);
	// std::cout << "Adding number " << n << std::endl;
	numbersVec.push_back(n);
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
		std::cout << std::endl;
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
}

// Version pour Vector
std::vector<int> PmergeMe::generateJacobsthalSequenceVec(int n)
{
	std::vector<int> jacobsthal;
	// On commence directement avec 3 (le troisième nombre de Jacobsthal)
	jacobsthal.push_back(3);
	
	// Variables temporaires pour calculer les prochains nombres
	int prev2 = 1; // Le nombre précédent (1)
	int prev1 = 3; // Le nombre actuel (3)
	
	// Génération des nombres suivants
	for (int i = 1; i < n; ++i)
	{
		int next = prev1 + 2 * prev2;
		jacobsthal.push_back(next);
		prev2 = prev1;
		prev1 = next;
	}
	return jacobsthal;
}

void PmergeMe::sort()
{
	if (numbersVec.empty())
		return;
	// Tri avec mesure du temps pour vector
	double startVec = getCurrentTime();
	fordJohnsonSortVec(numbersVec);
	double endVec = getCurrentTime();
	timeVector = endVec - startVec;
}

void PmergeMe::fordJohnsonSortVec(std::vector<int>& vec)
{
	if (vec.size() <= 1) return;

	// 1. Former des paires
	std::vector<std::pair<int, int> > pairs;
	size_t i;
	for (i = 0; i < vec.size() - 1; i += 2)
	{
		int a = vec[i], b = vec[i + 1];
		pairs.push_back(std::make_pair(a, b));
	}
	// Gérer l'élément restant si la taille est impaire
	int straggler = -1;
	if (i < vec.size())
		straggler = vec[i];

	// 2. Déterminer le plus grand des deux éléments et créer des paires triées
	std::vector<std::pair<int, int> > sortedPairs;
	for (size_t j = 0; j < pairs.size(); ++j)
	{
		if (pairs[j].first > pairs[j].second)
			sortedPairs.push_back(pairs[j]);
		else
			sortedPairs.push_back(std::make_pair(pairs[j].second, pairs[j].first));
	}
	std::cout << std::endl;
	
	// 3. Extraire les plus grands éléments
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

	// 4. Extraire les éléments plus grands des paires triées et extraire les plus petits
	vec.clear();
	// Créer la chaîne principale avec les plus grands éléments
	for (size_t j = 0; j < sortedPairs.size(); ++j)
		vec.push_back(sortedPairs[j].first);
	// Collecter les éléments plus petits
	std::vector<int> pend;
	for (size_t j = 0; j < sortedPairs.size(); ++j)
		pend.push_back(sortedPairs[j].second);
	// Optimisation : Insérer le premier élément de pend directement
	if (!pend.empty())
	{
		vec.insert(vec.begin(), pend[0]);
	}

	// 5. Générer la séquence de Jacobsthal et l'ordre d'insertion
	std::vector<int> insertionOrder;
	std::vector<int> jacobsthal = generateJacobsthalSequenceVec(pend.size());
	
	// Pour chaque nombre de Jacobsthal jusqu'à ce que tous les indices soient traités
	std::vector<bool> processed(pend.size(), false);
	for (size_t i = 0; i < jacobsthal.size() && insertionOrder.size() < pend.size(); i++)
	{
		// Ajouter d'abord le nombre de Jacobsthal
		if (jacobsthal[i] < static_cast<int>(pend.size()))
		{
			insertionOrder.push_back(jacobsthal[i]);
		}
		// Définir la limite inférieure
		int lowerBound;
		if (i > 0)
			lowerBound = jacobsthal[i-1];
		else
			lowerBound = -1;
		// Puis ajouter tous les indices qui le précèdent
		for (int j = jacobsthal[i] - 1; j > lowerBound && j >= 1; --j)
		{
			if (j < static_cast<int>(pend.size()) && !processed[j])
			{
				insertionOrder.push_back(j);
				processed[j] = true;
			}
		}		
	}

	// 6. Insérer selon la séquence de Jacobsthal
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
	// 7. Insérer l'élément restant si nécessaire
	if (straggler != -1)
	{
		std::vector<int>::iterator pos = 
			std::lower_bound(vec.begin(), vec.end(), straggler);
		vec.insert(pos, straggler);
	}
}
