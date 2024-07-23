/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:18:52 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/22 22:50:42 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
	public:
		virtual ~Base();

};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
