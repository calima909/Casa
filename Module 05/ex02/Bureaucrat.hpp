/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:44:27 by fchiocci          #+#    #+#             */
/*   Updated: 2023/10/26 16:12:21 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#   define BUREAUCRAT_HPP

#   include <iostream>
#   include <stdexcept>

class AForm;

class Bureaucrat 
{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &toCopy);
        ~Bureaucrat();
        
        int getGrade() const;
        const std::string &getName() const;
        void incrementGrade();
        void decrementGrade();

        void signForm(AForm &form);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too high.";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade is too low.";
                }
        };

        void executeForm(AForm const &form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif