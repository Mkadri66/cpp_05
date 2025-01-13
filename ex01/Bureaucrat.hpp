/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:34:57 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/13 11:54:05 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Form.hpp"

class	Bureaucrat {

	private:

	std::string	const	_name;
	int					_grade;

	public:

	Bureaucrat();
	Bureaucrat(Bureaucrat const & copy);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	Bureaucrat&			operator=(Bureaucrat const & rhs);
	std::string const&	getName() const;
	int					getGrade() const;
	void				setGrade(int grade);

	void	incrementGrade();
	void	decrementGrade();
	void	signForm(Form& form) const;

	class GradeTooHighException : public std::exception {

		public:
		virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
		virtual const char* what() const throw();
	};
};

std::ostream &	operator<<(std::ostream & op, Bureaucrat const & b);

#endif