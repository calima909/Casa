/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:44:38 by fchiocci          #+#    #+#             */
/*   Updated: 2023/10/26 14:16:15 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#   define FORM_HPP

#   include <iostream>
#   include <stdexcept>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeSign;
        const int gradeExec;
        
    public:
        Form();
        Form(const std::string& name, int gradeSign, int gradeExec);
        Form(const Form &toCopy);
        ~Form();
        
        Form& operator=(const Form &toCopy);

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(const Bureaucrat& bureaucrat);
        
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

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif