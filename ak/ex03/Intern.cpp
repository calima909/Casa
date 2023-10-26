/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:53:47 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/18 18:08:46 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern (void)
{
	
}

Intern::~Intern( void )
{
	
}

AForm *Intern::makeForm (std::string form_name, std::string target)
{
	int i;
	AForm*    forms[] = {
        new RobotomyRequestForm( target ),
        new PresidentialPardonForm( target ),
        new ShrubberyCreationForm( target )
    };
	std::string names[] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	for (i = 0; i < 3 && names[i].compare(form_name); i++)
		;
	if (i < 3)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j != i)
			{
				delete forms[j];
			}
		}
		std::cout << "Intern creates " << forms[i]->getName() << std::endl;
		return (forms[i]);
	}
	std::cout << "Error creating the forms, form doesn't exist!" << std::endl;
	return(NULL);
}
