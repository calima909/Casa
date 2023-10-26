/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:44:38 by fchiocci          #+#    #+#             */
/*   Updated: 2023/10/26 16:42:59 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#   define AFORM_HPP

#   include <iostream>
#   include <stdexcept>
#   include <fstream>
#   include <string>
#   include <cstdlib>
#   include <time.h>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeSign;
        const int gradeExec;
        
    public:
        AForm();
        AForm(const std::string& name, int gradeSign, int gradeExec);
        AForm(const AForm &toCopy);
        virtual ~AForm();
               
        AForm& operator=(const AForm &toCopy);

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(const Bureaucrat& bureaucrat);

        virtual void execute(Bureaucrat const & executor) const = 0;
        
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

};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif