/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:12:29 by jhurpy            #+#    #+#             */
/*   Updated: 2024/08/06 09:51:17 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <set>

class span
{
	public:
		span(unsigned int n);
		~span();

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

	private:
		unsigned int	N;
		std::set<int>	set;

		span();
		span(const span &span);

		span &operator=(const span &span);
};


#endif
