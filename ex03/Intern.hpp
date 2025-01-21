/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:56:30 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/20 19:56:53 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {

	public: 

	Intern();
	Intern(Intern const& copy);
	~Intern();

	Intern&	operator=(Intern const& rhs);

	AForm*	makeForm(std::string formName, std::string formTarget);

	class WrongFormNameException : public std::exception {
		public:
		virtual const char* what() const throw();
	};
};

#endif