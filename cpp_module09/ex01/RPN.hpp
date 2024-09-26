/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:49:10 by jhurpy            #+#    #+#             */
/*   Updated: 2024/09/26 11:32:19 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstring>
# include <cstdlib>

class RPN
{
	private:
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);

		std::stack<int> _stack;
		int _result;

		void _calculate(const char * str);
		bool _isDigit(const char & c);
		bool _isOperator(const char & c);
		void _makeOperation(const char & c);

	public:
		RPN(const char * str);
		~RPN();
};




#endif
