/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:29:45 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/13 11:54:44 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExec): _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	this->_signed = false;
}

Form::Form(Form const& copy):
	_name(copy.getName()), 
	_gradeToSign(copy.getGradeToSign()),
	_gradeToExec(copy.getGradeToSign()) 
{
	*this=copy;
}

Form::~Form() {}


Form&	Form::operator=(Form const& rhs) {
	if (this != &rhs) {
		_signed = rhs.getSigned();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & op, Form const & b) {

	op << "Is " << b.getName() << " Form signed : ";
	if (b.getSigned() == false)
		op << " no." << std::endl;
	else
		op << " yes." << std::endl;
	op << b.getName() << " Form needed grade to sign it : " << b.getGradeToSign() << std::endl;
	op << b.getName() << " Form needed grade to execute it : " << b.getGradeToExec() << std::endl;
	
	return op;
}

std::string const	Form::getName() const {
	return this->_name;
}

bool	Form::getSigned() const {
	return this->_signed;
}

int	Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int	Form::getGradeToExec() const {
	return this->_gradeToExec;
}

void	Form::beSigned(Bureaucrat const& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return (" his/her grade is too high.");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return (" his/her grade is too low");
}