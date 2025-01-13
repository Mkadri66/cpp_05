/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:35:14 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/13 11:53:22 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() {};

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){

	try {
		_grade = grade;
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (std::exception & e){
		std::cout << "constructor of this class with '" << _name << "' " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) {
	*this=copy;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& 	Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs) {
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::string const &	Bureaucrat::getName() const {
	return this->_name;
}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

void	Bureaucrat::setGrade(int grade) {
	this->_grade = grade;
}

void	Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrementGrade() {
	
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void	Bureaucrat::signForm(Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because" << e.what() << std::endl;
	}

}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return (" grade is too high.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return (" grade is too low");
}

std::ostream&	operator<<(std::ostream & op, Bureaucrat const & b) {
	op << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return op;
}