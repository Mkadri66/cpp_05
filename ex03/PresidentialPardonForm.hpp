/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:14:19 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/20 20:02:57 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <stdexcept>

class PresidentialPardonForm : public AForm {

	private:

	std::string	_target;

	public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const& copy);
	~PresidentialPardonForm();

	PresidentialPardonForm&	operator=(PresidentialPardonForm const& rhs);

	std::string	getTarget() const;

	void	execute(Bureaucrat const& executor) const;
	static AForm*	createForm(std::string target);
};

std::ostream &	operator<<(std::ostream & op, PresidentialPardonForm const & b);

#endif