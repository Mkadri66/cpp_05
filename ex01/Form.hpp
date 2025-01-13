/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:29:34 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/13 11:45:38 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:

	std::string const	_name;
	bool				_signed;
	int const			_gradeToSign;
	int const			_gradeToExec;

	public:

	Form();
	Form(std::string name, int gradeToSign, int gradeToExec);
	Form(Form const& copy);
	~Form();

	Form&	operator=(Form const& rhs);

	std::string const	getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;

	void	beSigned(Bureaucrat const& bureaucrat);

	class GradeTooHighException : public std::exception {

	public:
	virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
		virtual const char* what() const throw();
	};
};

std::ostream &	operator<<(std::ostream & op, Form const & b);

#endif