/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:22:14 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/25 17:42:40 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	try
	{
		Bureaucrat test("diahane", 1);
		Bureaucrat test2("B2", 1);
		Form testform("porcodioform", 2, 1);
		Form testform2("form2", 2, 1);
		
		/* //testform.beSigned(test);
		
		//test.signForm(testform);
		std::cout << testform << std::endl;
		std::cout << test << std::endl;
		//test.incrGrade();
		
		//testform.beSigned(test); */
		test.signForm(testform);
		test.signForm(testform);
		test.signForm(testform);
		test2.signForm(testform2);
		test2.signForm(testform2);
		
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
