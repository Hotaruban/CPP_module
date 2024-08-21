/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:58:45 by jhurpy            #+#    #+#             */
/*   Updated: 2024/08/21 14:21:31 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

int main(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(42);
	mstack.push(737);

	std::cout << "----------------" << std::endl;

	std::cout << "Top: " << mstack.top() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "----------------" << std::endl;

	std::cout << "Top before pop: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Top after pop: " << mstack.top() << std::endl;

	it = mstack.begin();
	ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "----------------" << std::endl;

	std::cout << "Top before push: " << mstack.top() << std::endl;
	mstack.push(100);
	std::cout << "Top after push: " << mstack.top() << std::endl;
	it = mstack.begin();
	ite = mstack.end();

	std::cout << "Reverse order:" << std::endl;
	while (ite != it) {
		--ite;
		std::cout << *ite << std::endl;
	}

	std::cout << "----------------" << std::endl;

	std::cout << "For loop:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "----------------" << std::endl;

	return 0;
}
