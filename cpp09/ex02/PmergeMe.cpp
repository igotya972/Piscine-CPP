/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:41:05 by dferjul           #+#    #+#             */
/*   Updated: 2025/01/17 00:54:02 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) 
{
	this->numbers = copy.numbers;
	this->numbersVec = copy.numbersVec;
	this->timeList = copy.timeList;
	this->timeVector = copy.timeVector;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		this->numbers = copy.numbers;
		this->numbersVec = copy.numbersVec;
		this->timeList = copy.timeList;
		this->timeVector = copy.timeVector;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort()
{
	if (numbers.empty() || numbersVec.empty())
		return;

	// Tri avec mesure du temps pour vector
	double startVec = getCurrentTime();
	fordJohnsonSortVec(numbersVec);
	double endVec = getCurrentTime();
	timeVector = endVec - startVec;

	// Tri avec mesure du temps pour list
	double startList = getCurrentTime();
	numbers.clear();
	numbers.insert(numbers.begin(), numbersVec.begin(), numbersVec.end());
	timeList = getCurrentTime() - startList;
}

void PmergeMe::addNumber(int n)
{
	// Vérifier les doublons dans le vector (plus rapide que la liste)
	if (std::find(numbersVec.begin(), numbersVec.end(), n) != numbersVec.end())
	{
		throw std::runtime_error("Error: duplicate numbers are not allowed");
	}
	
	// Si pas de doublon, ajouter aux deux conteneurs
	numbers.push_back(n);
	numbersVec.push_back(n);
}

void PmergeMe::display() const
{
	static bool firstCall = true;

	if (firstCall)
	{
		std::cout << "Before:  ";
		for (std::list<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		firstCall = false;
	}
	else
	{
		std::cout << "After:   ";
		for (std::vector<int>::const_iterator it = numbersVec.begin(); it != numbersVec.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		displayTime();
	}
}

void PmergeMe::displayTime() const
{
	std::cout << "Time to process a range of " << numbers.size() 
			  << " elements with std::list : " << std::fixed 
			  << std::setprecision(5) << timeList << " ms" << std::endl;
	
	std::cout << "Time to process a range of " << numbersVec.size() 
			  << " elements with std::vector : " << std::fixed 
			  << std::setprecision(5) << timeVector << " ms" << std::endl;
}

// Génération de la séquence de Jacobsthal
std::vector<int> PmergeMe::generateJacobsthalSequence(int n)
{
	std::vector<int> sequence;
	if (n <= 0) return sequence;
	
	sequence.push_back(0);
	if (n == 1) return sequence;
	sequence.push_back(1);
	
	for (int i = 2; i < n; ++i)
	{
		int next = sequence[i-1] + 2 * sequence[i-2];
		if (next >= n) break;
		sequence.push_back(next);
	}
	return sequence;
}

void PmergeMe::fordJohnsonSortVec(std::vector<int>& vec)
{
	if (vec.size() <= 1) return;

	// 1. Former des paires et trier chaque paire
	std::vector<std::pair<int, int> > pairs;
	size_t i;
	for (i = 0; i < vec.size() - 1; i += 2)
	{
		int a = vec[i], b = vec[i + 1];
		pairs.push_back(std::make_pair(std::max(a, b), std::min(a, b)));
	}

	// Gérer l'élément restant si la taille est impaire
	int straggler = -1;
	if (i < vec.size())
		straggler = vec[i];

	// 2. Trier récursivement les éléments plus grands
	std::vector<int> larger;
	for (size_t j = 0; j < pairs.size(); ++j)
		larger.push_back(pairs[j].first);
	
	fordJohnsonSortVec(larger);

	// 3. Reconstruire le vecteur avec les éléments plus grands
	vec.clear();
	for (size_t j = 0; j < larger.size(); ++j)
		vec.push_back(larger[j]);

	// 4. Collecter les éléments plus petits
	std::vector<int> smaller;
	for (size_t j = 0; j < pairs.size(); ++j)
		smaller.push_back(pairs[j].second);

	// 5. Utiliser la séquence de Jacobsthal pour l'ordre d'insertion
	std::vector<int> jacobsthal = generateJacobsthalSequence(smaller.size());
	
	// 6. Insérer selon la séquence de Jacobsthal
	for (size_t j = 0; j < jacobsthal.size(); ++j)
	{
		if (jacobsthal[j] < static_cast<int>(smaller.size()))
		{
			std::vector<int>::iterator pos = 
				std::lower_bound(vec.begin(), vec.end(), smaller[jacobsthal[j]]);
			vec.insert(pos, smaller[jacobsthal[j]]);
		}
	}

	// 7. Insérer les éléments restants
	for (size_t j = 0; j < smaller.size(); ++j)
	{
		if (std::find(vec.begin(), vec.end(), smaller[j]) == vec.end())
		{
			std::vector<int>::iterator pos = 
				std::lower_bound(vec.begin(), vec.end(), smaller[j]);
			vec.insert(pos, smaller[j]);
		}
	}

	// 8. Insérer l'élément restant si nécessaire
	if (straggler != -1)
	{
		std::vector<int>::iterator pos = 
			std::lower_bound(vec.begin(), vec.end(), straggler);
		vec.insert(pos, straggler);
	}
}

double PmergeMe::getCurrentTime() const
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec) / 1000.0;
}