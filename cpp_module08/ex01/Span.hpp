/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:12:29 by jhurpy            #+#    #+#             */
/*   Updated: 2024/08/07 14:29:24 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>

class span
{
	public:
		span(unsigned int n);
		~span();

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

		class numberFullException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "The number is full";
				}
		};

		class numberEmptyException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "The number is empty or contains only one element";
				}
		};

	private:
		unsigned int	N;
		std::vector<int>	vector;

		span();
		span(const span &span);

		span &operator=(const span &span);
};


#endif
