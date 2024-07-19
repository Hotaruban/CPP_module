/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:21:23 by jhurpy            #+#    #+#             */
/*   Updated: 2024/07/19 23:24:07 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:

		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm & src);
		~PresidentialPardonForm();

		PresidentialPardonForm & operator=(const PresidentialPardonForm & src);

		void execute(Bureaucrat const & executor) const;

	private:

		std::string _target;
};

#endif
