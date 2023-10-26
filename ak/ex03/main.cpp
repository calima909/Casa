/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:22:14 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/21 13:14:24 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main ()
{
	try
	{
		Intern someRandomIntern;
		AForm* testform;
		testform = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat test("diahane", 3);
		
		test.incrGrade();
		
		test.signForm(testform);
		
		test.executeForm(*testform);
		delete testform;
		
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
