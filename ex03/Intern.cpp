/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:57:10 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/20 19:57:13 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const& copy) {
	*this=copy;
}

Intern::~Intern() {}

Intern&	Intern::operator=(Intern const& rhs) {
	(void)rhs;
	return *this;	
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget) {

	std::string	names[3] = {"presidential pardon", "shrubbery creation", "robotomy request"};
	AForm* (*formCreator[3])(std::string Target) = {PresidentialPardonForm::createForm, ShrubberyCreationForm::createForm, RobotomyRequestForm::createForm}; 
	for (int i = 0; i < 4; i++) {
		if (names[i] == formName) {
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return formCreator[i](formTarget);
		}
	}
	throw WrongFormNameException();
}

const char*	Intern::WrongFormNameException::what() const throw() {
	return "this form doesn't exist. Please chose among those ones : presidential pardon, shrubbery creation, robotomy request";
}