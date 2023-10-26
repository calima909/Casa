/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:44:42 by fchiocci          #+#    #+#             */
/*   Updated: 2023/10/25 16:44:43 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    /* try
    { */
        Bureaucrat bureaucrat1("Gino", 100);
        Bureaucrat bureaucrat2("Pino", 1);
        Form form1("Form 1", 10, 10);
        Form form2("Form 2", 1, 1);
        
        std::cout << bureaucrat1 << std::endl << bureaucrat2 << std::endl;
        //std::cout << form1 << std::endl;

        bureaucrat1.signForm(form1);
        bureaucrat1.signForm(form2);
        bureaucrat2.signForm(form1);
        bureaucrat2.signForm(form2);
    /* }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    } */
    return 0;
}