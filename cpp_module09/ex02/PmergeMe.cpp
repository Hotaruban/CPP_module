/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:49:12 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/16 22:01:15 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **av, int & ac)
{
	_isNumber(av, ac);
	_makeIntegers(av, ac);
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
		(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

// implement the containers of int inside a container of pairs of containers of int
template <typename T, typename TofT>
void PmergeMe::_containerOfContainers(T & container, TofT & containerOfContainers)
{
	typename T::iterator it = container.begin();
	T tmp1, tmp2;

	while (it != container.end())
	{
		tmp1.push_back(*it);
		it++;
		if (it != container.end())
		{
			tmp2.push_back(*it);
			it++;
		}
		containerOfContainers.push_back(std::pair<T, T>(tmp1, tmp2));
		tmp1.clear();
		tmp2.clear();
	}
}

// sort the pair of containers of int and return the sorted container
template <typename T, typename TofT>
void PmergeMe::_sortPair(TofT & cont)
{
	TofT tmp;
	T tmp1, tmp2;

	for (typename TofT::iterator it = cont.begin(); it != cont.end(); it++)
	{
		_sortContainerInt(it->first, it->second);

		if (tmp1.empty())
			tmp1 = it->first;
		else
			tmp2 = it->first;

		if (!tmp1.empty() && !tmp2.empty())
		{
			tmp.push_back(std::make_pair(tmp1, tmp2));
			tmp1.clear();
			tmp2.clear();
		}
	}
	if (!tmp1.empty())
	{
		tmp.push_back(std::make_pair(tmp1, T()));
		tmp1.clear();
		tmp2.clear();
	}
	cont = tmp;
}

// sort the container of int and merge the two containers
template <typename T>
void PmergeMe::_sortContainerInt(T &cont1, T &cont2)
{
	T tmp;
	typename T::iterator it1 = cont1.begin();
	typename T::iterator it2 = cont2.begin();

	while (it1 != cont1.end() && it2 != cont2.end())
	{
		if (*it1 < *it2)
		{
			tmp.push_back(*it1);
			it1++;
		}
		else
		{
			tmp.push_back(*it2);
			it2++;
		}
	}

	tmp.insert(tmp.end(), it1, cont1.end());
	tmp.insert(tmp.end(), it2, cont2.end());

	cont1 = tmp;
	cont2.clear();
}

void PmergeMe::sortVec()
{
	//gettimeofday(&_startTime, NULL);
	_start = clock();

	_containerOfContainers(_vector, _vectorV);

	while (_vectorV.size() > 1)
		_sortPair<std::vector<int>, std::vector<std::pair<std::vector<int>, std::vector<int> > > >(_vectorV);

	_sortPair<std::vector<int>, std::vector<std::pair<std::vector<int>, std::vector<int> > > >(_vectorV);

	_vector = _vectorV[0].first;

	//gettimeofday(&_endTime, NULL);
	_end = clock();

	_printSortedNumbers(_vector);
	_printTime("std::vector");
}

void PmergeMe::sortList()
{
	//gettimeofday(&_startTime, NULL);
	_start = clock();

	_containerOfContainers(_list, _listL);

	while (_listL.size() > 1)
	{
		_sortPair<std::list<int>, std::list<std::pair<std::list<int>, std::list<int> > > >(_listL);
	}
	_sortPair<std::list<int>, std::list<std::pair<std::list<int>, std::list<int> > > >(_listL);

	_list = _listL.front().first;

	//gettimeofday(&_endTime, NULL);
	_end = clock();

	//_printSortedNumbers(_list);
	_printTime("std::list");
}

void	PmergeMe::printUnsortedNumbers(char **av, int & ac)
{
	std::cout << "Before sorting:\t";
	for (int i = 1; i < ac; i++)
	{
		std::cout << av[i] << " ";
		if (i > 6)
		{
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
}

template <typename T>
void	PmergeMe::_printSortedNumbers(T & cont)
{
	std::cout << "After sorting:\t";
	for (typename T::iterator it = cont.begin(); it != cont.end(); it++)
	{
		std::cout << *it << " ";
		if (std::distance(cont.begin(), it) > 5)
		{
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
}

void	PmergeMe::_printTime(std::string container)
{
	double duraclock = static_cast<double>(_end - _start) / CLOCKS_PER_SEC * 1e6;

	//long seconds = _endTime.tv_sec - _startTime.tv_sec;
	//long microseconds = _endTime.tv_usec - _startTime.tv_usec;
	//double duration = seconds * 1e-6 + microseconds;
	//std::cout << "Time to process a range of " << _size << " elements with " << container << "(): " << duration << " us" << std::endl;

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Time to process a range of " << _size << " elements with " << container << "(): " << duraclock << " us" << std::endl;

}

void PmergeMe::_makeIntegers(char **av, int & ac)
{
	unsigned int number;
	_size = ac - 1;

	for (int i = 1; i < ac; i++)
	{
		number = std::atol(av[i]);
		if (number > INT_MAX)
			throw std::invalid_argument("Error: invalid argument: " + std::string(av[i]));
		_vector.push_back((int) number);
		_list.push_back((int) number);
	}
}

bool	PmergeMe::_isNumber(char **av, int & ac)
{
	for (int i = 1; i < ac; i++)
		for (int j = 0; av[i][j]; j++)
			if (!std::isdigit(av[i][j]) && !std::isspace(av[i][j]))
				throw std::invalid_argument("Error: invalid argument [isNumber]: " + std::string(av[i]));
	return (true);
}
