/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:25:44 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/17 17:26:02 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:

	std::string const	_name;
	bool				_signed;
	int const			_gradeToSign;
	int const			_gradeToExec;

	public:

	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExec);
	AForm(AForm const& copy);
	virtual ~AForm();

	AForm&	operator=(AForm const& rhs);

	std::string const	getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;

	virtual void	beSigned(Bureaucrat const& bureaucrat);
	virtual void	execute(Bureaucrat const& executor) const = 0;

	class GradeTooHighException : public std::exception {

	public:
	virtual const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {

		public:
		virtual const char* what() const throw();
	};

	class FormAlreadySignedException : public std::exception {

		public:
		virtual const char* what() const throw();
	};
};



std::ostream &	operator<<(std::ostream & op, AForm const & b);

#endif