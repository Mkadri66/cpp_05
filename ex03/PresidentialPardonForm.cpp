/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:14:55 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/20 20:02:04 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target(NULL) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & copy ) : AForm("PresidentialPardonForm", 25, 5), _target(NULL) {
	*this=copy;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}


PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs) {

	if (this != &rhs) {
		_target = rhs.getTarget();
	}
	return *this;
	
}

std::ostream &	operator<<(std::ostream & op, PresidentialPardonForm const & b) {

	op << "Is " << b.getName() << " Form signed : ";
	if (b.getSigned() == false)
		op << " no." << std::endl;
	else
		op << " yes." << std::endl;
	op << b.getName() << " Form needed grade to sign it : " << b.getGradeToSign() << std::endl;
	op << b.getName() << " Form needed grade to execute it : " << b.getGradeToExec() << std::endl;
	op << "this " << b.getName() <<  "Form is for " << b.getTarget() << std::endl;
	
	return op;
}


std::string	PresidentialPardonForm::getTarget() const {
	return this->_target;
}


void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {

	if (getSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() < getGradeToExec()) {
		throw GradeTooLowException();
	}
	else {
		std::cout << "Dear " << _target << ", you have been pardonned by president Zaphod Beeblebrox !" << std::endl;
	}
}

AForm*	PresidentialPardonForm::createForm(std::string target) {
	return new PresidentialPardonForm(target);
}