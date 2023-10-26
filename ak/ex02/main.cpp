/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:22:14 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/21 13:13:29 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	try
	{
		Bureaucrat test("diahane", 3);
		AForm *testform = new ShrubberyCreationForm("porcodioform");
		
		test.executeForm(*testform);
		
		std::cout << *testform << std::endl;
		std::cout << test << std::endl;
		
		test.signForm(testform);
		test.executeForm(*testform);
		delete testform;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
