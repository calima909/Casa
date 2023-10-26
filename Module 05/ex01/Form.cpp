/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:44:35 by fchiocci          #+#    #+#             */
/*   Updated: 2023/10/25 16:44:36 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(const std::string& name, int gradeSign, int gradeExec) : name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    std::cout << "Form Constructor called" << std::endl;
}

Form::Form(const Form &toCopy) : name(toCopy.name), isSigned(toCopy.isSigned), gradeSign(toCopy.gradeSign), gradeExec(toCopy.gradeExec)
{
    std::cout << "Copy constructor called" << std::endl;
    if (toCopy.gradeSign < 1 || toCopy.gradeExec < 1)
        throw GradeTooHighException();
    else if (toCopy.gradeSign > 150 || toCopy.gradeExec > 150)
        throw GradeTooLowException();
}

Form::~Form()
{
    std::cout << "Form Destructor called" << std::endl;
}

const std::string& Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeSign() const
{
    return gradeSign;
}

int Form::getGradeExec() const
{
    return gradeExec;
}

class GradeTooHighException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Bureaucrat Grade is too low, required grade is too low.";
        }
};

class GradeTooLowException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Bureaucrat Grade is too high, required grade is too low.";
        }
};

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeSign)
    {
        isSigned = true;
        std::cout << bureaucrat.getName() << " signed " << name << std::endl;
    }
    else
    {
        std::cout << bureaucrat.getName() << " couldn't sign " << name << " because required grade sign is too low" << std::endl << std::flush;
        throw GradeTooLowException();
    }
}

Form& Form::operator=(const Form &rhs)
{
    if (this != &rhs) {
		this->isSigned = rhs.isSigned;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Form &Form)
{
    os << Form.getName() << ", Form grade " << Form.getGradeSign() << " to sign and " << Form.getGradeExec() << " to execute." << std::endl;
    return os;
}