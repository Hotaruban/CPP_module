/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:02:10 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/19 23:03:47 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		~RobotomyRequestForm();
		RobotomyRequestForm & operator=(RobotomyRequestForm const & src);

		void	execute(Bureaucrat const & executor) const;

		class RobotomizeException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Robotomize failed.");
				}
		};

	private:
		std::string const	_target;
};

#endif
