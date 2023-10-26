/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:43:39 by fchiocci          #+#    #+#             */
/*   Updated: 2023/10/25 16:43:40 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
int main()
{
    
    Bureaucrat gino("Gino", 1);
    Bureaucrat pino("Pino", 149);
    
    std::cout << gino << std::endl;
    std::cout << pino << std::endl;

    gino.incrementGrade();
    pino.decrementGrade();

    std::cout << gino << std::endl;
    std::cout << pino << std::endl;

    gino.incrementGrade();
    pino.decrementGrade();

    std::cout << gino << std::endl;
    std::cout << pino << std::endl;
    
    return 0;
}