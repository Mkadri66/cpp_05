/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:37:33 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/20 20:03:52 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target(NULL) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & copy ) : AForm("PresidentialPardonForm", 25, 5), _target(NULL) {
	*this=copy;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}


RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {

	if (this != &rhs) {
		_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & op, RobotomyRequestForm const & b) {

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


std::string	RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {

	if (getSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() < getGradeToExec()) {
		throw GradeTooLowException();
	}
	else {
		std::cout << "* DRILLING NOISE *" << std::endl;

		srand(time(0));
		int	randomNumber = rand() % 100;

		if (randomNumber < 50) {
			std::cout << "Dear " << _target << ", you've been succesfully robotomized" << std::endl;
		}
		else {
			std::cout << "Oops. Dear " << _target << ", your robotomy has sadly failed. Please try again." << std::endl;
		}
	}
}

AForm*	RobotomyRequestForm::createForm(std::string target) {
	return new RobotomyRequestForm(target);
}