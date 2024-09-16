/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:49:14 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/16 21:12:37 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "logTab.hpp"
# include <sstream>
# include <iostream>
# include <sys/time.h>
# include <vector>
# include <list>


class PmergeMe
{
	public:
		PmergeMe(char **av, int & ac);
		~PmergeMe();

		void	sortVec();
		void	sortList();
		void	printUnsortedNumbers(char **av, int & ac);

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		template <typename T, typename TofT>
		void	_containerOfContainers(T & container, TofT & containerOfContainers);
		template <typename T, typename TofT>
		void	_sortPair(TofT & cont);
		template <typename T>
		void	_sortContainerInt(T & cont1, T & cont2);
		template <typename T>
		void	_printSortedNumbers(T & cont);

		size_t							_size;
		std::vector<int>				_vector;
		std::vector<std::pair<std::vector<int>, std::vector<int> > >	_vectorV;
		std::list<int>					_list;
		std::list<std::pair<std::list<int>, std::list<int> > >		_listL;
		struct timeval		_startTime, _endTime;

		void	_makeIntegers(char **av, int & ac);
		void	_printTime(std::string container);
};

#endif
