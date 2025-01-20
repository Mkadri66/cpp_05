/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:29:37 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/17 17:30:20 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm(): _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec): _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	this->_signed = false;
}

AForm::AForm(AForm const& copy):
	_name(copy.getName()), 
	_gradeToSign(copy.getGradeToSign()),
	_gradeToExec(copy.getGradeToSign()) 
{
	*this=copy;
}

AForm::~AForm() {}


AForm&	AForm::operator=(AForm const& rhs) {
	if (this != &rhs) {
		_signed = rhs.getSigned();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & op, AForm const & b) {

	op << "Is " << b.getName() << " AForm signed : ";
	if (b.getSigned() == false)
		op << " no." << std::endl;
	else
		op << " yes." << std::endl;
	op << b.getName() << " Form needed grade to sign it : " << b.getGradeToSign() << std::endl;
	op << b.getName() << " Form needed grade to execute it : " << b.getGradeToExec() << std::endl;
	
	return op;
}

std::string const	AForm::getName() const {
	return this->_name;
}

bool	AForm::getSigned() const {
	return this->_signed;
}

int	AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int	AForm::getGradeToExec() const {
	return this->_gradeToExec;
}



void	AForm::beSigned(Bureaucrat const& bureaucrat) {
	
	if (getSigned() == true) 
		throw AForm::FormAlreadySignedException();
	else if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}


const char*	AForm::GradeTooHighException::what() const throw() {
	return (" his/her grade is too high.");
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return (" his/her grade is too low");
}

const char*	AForm::FormNotSignedException::what() const throw() {
	return ("This form is not signed");
}

const char*	AForm::FormAlreadySignedException::what() const throw() {
	return ("This form is already signed");
}