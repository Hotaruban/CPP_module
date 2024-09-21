/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:46:25 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/21 22:46:05 by jhurpy           ###   ########.fr       */
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

	private:
		T		& _container;
		size_t	_size;
		clock_t	_start, _end;

		bool	_isNumber(char **av, int & ac);
		void	_generateJacobsthal(std::vector<size_t>& jacobsthal);
		void	_generateJacobsthal(std::list<size_t>& jacobsthal);


};

template <typename T>
PmergeMe<T>::PmergeMe(T & container) : _container(container) {}

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
/*                              VECTOR SPECIALIZATION                         */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void PmergeMe<T>::_generateJacobsthal(std::vector<size_t>& jacobsthal) {
	jacobsthal.push_back(1);
	jacobsthal.push_back(3);

	for (size_t i = 2; ; ++i)
	{
		size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		if (next > this->_size) break;
		jacobsthal.push_back(next);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                              LIST SPECIALIZATION                           */
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


#endif
