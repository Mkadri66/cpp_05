/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:42:43 by mkadri            #+#    #+#             */
/*   Updated: 2025/01/20 20:09:10 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <stdexcept>

class ShrubberyCreationForm : public AForm {

	private:

	std::string	_target;

	public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const& copy);
	~ShrubberyCreationForm();

	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& rhs);

	std::string	getTarget() const;

	void	execute(Bureaucrat const& executor) const;
	static AForm*	createForm(std::string target);
};

std::ostream &	operator<<(std::ostream & op, ShrubberyCreationForm const & b);

#endif