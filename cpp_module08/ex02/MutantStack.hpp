/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:17:53 by jhurpy            #+#    #+#             */
/*   Updated: 2024/08/21 14:17:02 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {};
	~MutantStack() {};
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
private:
	MutantStack(const MutantStack &stack) {
		*this = stack;
	};
	MutantStack &operator=(const MutantStack &stack) {
		if (this != &stack)
			*this = stack;
		return *this;
	}
};

#endif
