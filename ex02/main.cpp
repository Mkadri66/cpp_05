/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:22:21 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/20 19:32:38 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define CYAN "\033[36m"
# define RESET "\033[0m"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {

	Bureaucrat	Julien("Julien", 146);
	Bureaucrat	Charles("Charles", 156);
    Bureaucrat	Bob("Bob", 73);

	AForm*	shrub = new ShrubberyCreationForm("Julien");
    AForm*	prez = new PresidentialPardonForm("Charles");
	AForm*	rob = new RobotomyRequestForm("Bob");
	
////////////////////////////////////////////////////////////////////////////////////

	std::cout << CYAN << "\n------- JULIEN (starting grade : 146) : SHRUBBERY FORM -------\n" << RESET << std::endl;
	try {
		Julien.executeForm(*shrub);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Julien.signForm(*shrub);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	Julien.incrementGrade();
	Julien.signForm(*shrub);
	Julien.signForm(*shrub);
	while (Julien.getGrade() > shrub->getGradeToExec())
		Julien.incrementGrade();
	std::cout << std::endl << Julien;
	std::cout << std:: endl << *shrub << std::endl;
	try {
		Julien.executeForm(*shrub);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	
////////////////////////////////////////////////////////////////////////////////////

	std::cout << CYAN << "\n------- CHARLES (starting grade : 26) : PRESIDENTIAL PARDON FORM -------\n" << RESET << std::endl;
	try {
		Charles.executeForm(*prez);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Charles.signForm(*prez);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	Charles.incrementGrade();
	Charles.signForm(*prez);
	Charles.signForm(*prez);
	while (Charles.getGrade() > prez->getGradeToExec())
		Charles.incrementGrade();
	std::cout << std::endl << Charles;
	std::cout << std:: endl << *prez << std::endl;
	try {
		Charles.executeForm(*prez);
	}
	catch(const std::exception& e) {
		std::cerr << Charles.getName() << " couldn't sign the form. " << e.what() << '\n';
	}
	std::cout << std::endl;
////////////////////////////////////////////////////////////////////////////////////
	std::cout << CYAN << "\n------- BOB (starting grade : 73) && ROBOTOMY REQUEST FORM -------\n" << RESET << std::endl;
	try {
		Bob.executeForm(*rob);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Bob.signForm(*rob);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	Bob.incrementGrade();
	Bob.signForm(*rob);
	Bob.signForm(*rob);
	while (Bob.getGrade() > rob->getGradeToExec())
		Bob.incrementGrade();
	std::cout << std::endl << Bob;
	std::cout << std:: endl << *rob << std::endl;
	try {
		Bob.executeForm(*rob);
	}
	catch(const std::exception& e) {
		std::cerr << Bob.getName() << " couldn't sign the form. " << e.what() << '\n';
	}
	std::cout << std::endl;

	delete shrub;
	delete prez;
	delete rob;

	return 0;
}