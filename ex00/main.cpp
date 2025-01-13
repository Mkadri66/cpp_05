/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:34:17 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/09 19:37:35 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {

	Bureaucrat	Julien("julien", -1);
	Bureaucrat	Charles("Charles", 156);

	Julien.setGrade(1);
	Charles.setGrade(150);
	
	try {
		Julien.incrementGrade();
	}
	catch(const std::exception& e) {
		
		std::cerr << Julien.getName() << e.what() << '\n';
	}
	try {
		Charles.decrementGrade();
	}
	catch(const std::exception& e) {
		std::cerr << Charles.getName() << e.what() << '\n';
	}
	
	try {
		std::cout << Julien;
		Julien.decrementGrade();
		std::cout << Julien;
		std::cout << Charles;
		Charles.incrementGrade();
		std::cout << Charles;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}