/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:22:14 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/25 17:06:20 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
	try
	{
		Bureaucrat test("diahane", 1);
		//Bureaucrat test2("madonnina", 200);
		std::cout << test << std::endl;
		
		//test.decrGrade();
		Bureaucrat test2("diahane2", 2);
		std::cout << test << std::endl;
		test.incrGrade();
		test.incrGrade();
		
		std::cout << test << std::endl;
		test2.incrGrade();
		test2.incrGrade();
		test2.incrGrade();
		
		
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
