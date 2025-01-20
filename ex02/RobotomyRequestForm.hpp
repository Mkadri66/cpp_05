/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:36:40 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/20 13:37:09 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <stdexcept>

class RobotomyRequestForm : public AForm {

	private:

	std::string	_target;

	public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const& copy);
	~RobotomyRequestForm();

	RobotomyRequestForm&	operator=(RobotomyRequestForm const& rhs);

	std::string	getTarget() const;

	void	execute(Bureaucrat const& executor) const;
};

std::ostream &	operator<<(std::ostream & op, RobotomyRequestForm const & b);

#endif