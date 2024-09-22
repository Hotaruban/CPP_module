/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:46:25 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/22 17:01:41 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define SIZE_PRINT 100

# include <iostream>
# include <string>
# include <sstream>
# include <sys/time.h>
# include <ctime>
# include <iomanip>
# include <vector>
# include <list>

template <typename T>
class PmergeMe
{
	public:
		PmergeMe(T & container);
		~PmergeMe();

		void	makeIntegers(char **av, int ac);
		void	printContainer(std::string str, size_t size);
		void	startClock();
		void	endClock();
		void	returnTime();
		void	mergeInsert();

	private:
		T			_container;
		size_t		_size;
		clock_t		_start, _end;
		int			_last;


		typedef std::pair<int, int>		pairsInt;
		typedef std::vector<pairsInt>	vectorPairs;
		typedef std::list<pairsInt>		listPairs;

		bool	_isNumber(char **av, int & ac);
		// vector specialization
		void				_insert(vectorPairs &pairs, std::vector<size_t> & jabobsthal);
		void				_generateJacobsthal(std::vector<size_t> & jacobsthal);
		vectorPairs			_createPairs(std::vector<int> &container);
		int					_findMiddle(int & middle, std::vector<int> & containers);
		int					_findJacobsthal(int i);
		void				_sortPairs(vectorPairs &pairs);

		// list specialization
		//void				_generateJacobsthal(std::list<size_t>& jacobsthal);
		//pairsInt			_createPairs(std::list<int> &container);
		//void				_insert();
		//std::list<int>	_findMiddle(int & middle, std::list<int> & containers);

		// common methods
		int					_binarySearch(int target);
};

template <typename T>
PmergeMe<T>::PmergeMe(T & container) : _container(container), _last(-1) {}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
bool	PmergeMe<T>::_isNumber(char **av, int & ac)
{
	for (int i = 1; i < ac; i++)
		for (int j = 0; av[i][j]; j++)
			if (!std::isdigit(av[i][j]) && !std::isspace(av[i][j]))
				throw std::invalid_argument("Error: invalid argument [isNumber]: " + std::string(av[i]));
	return (true);
}

template <typename T>
void PmergeMe<T>::makeIntegers(char **av, int ac)
{
	if (ac < 1)
		throw std::invalid_argument("Usage: ./pmergme [list of integerS]");
	_isNumber(av, ac);
	this->_size = ac - 1;

	for (int i = 1; i < ac; i++)
	{
		char *endptr;
		long number = std::strtol(av[i], &endptr, 10);
		if (*endptr != '\0' || number < 0 || number > INT_MAX)
			throw std::invalid_argument("Error: invalid argument: " + std::string(av[i]));
		this->_container.push_back(static_cast<int>(number));
	}
}

template <typename T>
void	PmergeMe<T>::printContainer(std::string str, size_t size)
{
	std::cout << str;
	for (typename T::iterator it = this->_container.begin(); it != this->_container.end(); it++)
	{
		std::cout << *it << " ";
		if (std::distance(this->_container.begin(), it) == static_cast<long>(size))
		{
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::startClock() { this->_start = clock(); }

template <typename T>
void PmergeMe<T>::endClock() { this->_end = clock(); }

template <typename T>
void PmergeMe<T>::returnTime()
{
	double time = (double)(this->_end - this->_start) / CLOCKS_PER_SEC * 1e6;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Time to process a range of " << this->_size << " elements: " << time << " us" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                            VECTOR SPECIALIZATION                           */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	PmergeMe<T>::mergeInsert()
{
	vectorPairs pairs = _createPairs(_container);
	std::vector<size_t>	jabobsthal;

	_generateJacobsthal(jabobsthal);

	if (pairs.size() == 0) {
		_container.push_back(_last);
		return;
	}

	_sortPairs(pairs);

	_insert(pairs, jabobsthal);
}

template <typename T>
typename PmergeMe<T>::vectorPairs PmergeMe<T>::_createPairs(std::vector<int> &container) {
	vectorPairs	pairs;

	if (container.size() % 2 != 0) {
		_last = container.back();
		container.pop_back();
	}

	for (size_t i = 0; i < container.size(); i += 2) {
		if (container[i] < container[i + 1])
			std::swap(container[i], container[i + 1]);
		pairs.push_back(std::make_pair(container[i], container[i + 1]));
	}
	return (pairs);
}

template <typename T>
void PmergeMe<T>::_generateJacobsthal(std::vector<size_t> & jacobsthal) {
	int	jacobsthalSequence[_size];

	jacobsthalSequence[0] = 0;
	jacobsthalSequence[1] = 1;
	int	lastJabobsthalNumber = 2;

	for (size_t i = 2; jacobsthal.size() < _size; i++)
	{
		jacobsthalSequence[i] = 2 * jacobsthalSequence[i - 1] + jacobsthalSequence[i - 2];
		i != 2 ? jacobsthal.push_back(jacobsthalSequence[i - 1]) : (void)0;
		for (int j = jacobsthalSequence[i] - 1; j > lastJabobsthalNumber; j--)
			jacobsthal.push_back(j);
		lastJabobsthalNumber = jacobsthalSequence[i];
	}
}

template <typename Container>
void	PmergeMe<Container>::_sortPairs(vectorPairs &pairs)
{
	if (pairs.size() <= 1)
		return;

	size_t	middle = pairs.size() / 2;
	vectorPairs	left(pairs.begin(), pairs.begin() + middle);
	vectorPairs	right(pairs.begin() + middle, pairs.end());

	_sortPairs(left);
	_sortPairs(right);

	size_t	leftIndex = 0;
	size_t	rightIndex = 0;
	size_t	Index = 0;

	while (leftIndex < left.size() && rightIndex < right.size())
		pairs[Index++] = (left[leftIndex].first < right[rightIndex].first) ? left[leftIndex++] : right[rightIndex++];

	while (leftIndex < left.size())
		pairs[Index++] = left[leftIndex++];

	while (rightIndex < right.size())
		pairs[Index++] = right[rightIndex++];
}

template <typename T>
void	PmergeMe<T>::_insert(vectorPairs &pairs, std::vector<size_t> & jabobsthal)
{
	_container.clear();

	_container.push_back(pairs[0].second);

	for (size_t i = 0; i < pairs.size(); i++)
		_container.push_back(pairs[i].first);

	for (size_t i = 0; i < jabobsthal.size(); i++) {
		if (size_t(jabobsthal[i] - 1) >= pairs.size())
			continue;
		int index = _binarySearch(pairs[jabobsthal[i] - 1].second);
		_container.insert(_container.begin() + index, pairs[jabobsthal[i] - 1].second);
	}

	if (_last != -1) {
		int	index = _binarySearch(_last);
		_container.insert(_container.begin() + index, _last);
	}
}

template <typename T>
int PmergeMe<T>::_findMiddle(int & middle, std::vector<int> & containers)
{
	return (containers[middle]);
}

/* ************************************************************************** */
/*                                                                            */
/*                             LIST SPECIALIZATION                            */
/*                                                                            */
/* ************************************************************************** */

//template <typename T>
//void PmergeMe<T>::_generateJacobsthal(std::list<size_t>& jacobsthal) {
//	jacobsthal.push_back(1);
//	jacobsthal.push_back(3);

//	for (size_t i = 2; ; ++i)
//	{
//		size_t next = jacobsthal.back() + 2 * jacobsthal.front();
//		if (next > this->_size) break;
//		jacobsthal.push_back(next);
//	}
//}

//template <typename T>
//typename PmergeMe<T>::pairsInt PmergeMe<T>::_createPairs(std::list<int> &container) {
//	pairsInt	pairs;
//	return (pairs);
//}

//template <typename T>
//std::list<int> PmergeMe<T>::_findMiddle(int & middle, std::list<int> & containers)
//{
//	std::list<int>::iterator it = containers.begin();
//	std::advance(it, middle);
//	return (*it);
//}

//template <typename T>
//int PmergeMe<T>::_findJacobsthal(int i)
//{
//	std::list<size_t>::iterator it = _jacobsthal.begin();
//	std::advance(it, i);
//	return (*it);
//}

/* ************************************************************************** */
/*                                                                            */
/*                               GLOBAL METHODS                               */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
int	PmergeMe<T>::_binarySearch(int target)
{
	int	left = 0;
	int	right = _container.size() - 1;
	int	tmp;

	while (left <= right) {
		int	middle = (left + right) / 2;
		tmp = _findMiddle(middle, _container);
		if (tmp == target)
			return (middle);
		else if (tmp < target)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return (left);
}

#endif
