/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:49:14 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/14 01:35:20 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>

class PmergeMe
{
	public:
		PmergeMe(const char **av, int ac);
		~PmergeMe();

	private:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

};

#endif
