/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:44:35 by fchiocci          #+#    #+#             */
/*   Updated: 2023/10/26 16:23:02 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeSign, int gradeExec) : name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
    std::cout << "AForm Constructor called" << std::endl;
}

AForm::AForm(const AForm &toCopy) : name(toCopy.name), isSigned(toCopy.isSigned), gradeSign(toCopy.gradeSign), gradeExec(toCopy.gradeExec)
{
    std::cout << "Copy constructor called" << std::endl;
    if (toCopy.gradeSign < 1 || toCopy.gradeExec < 1)
        throw GradeTooHighException();
    else if (toCopy.gradeSign > 150 || toCopy.gradeExec > 150)
        throw GradeTooLowException();
}

AForm::~AForm()
{
    std::cout << "AForm Destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeSign() const
{
    return gradeSign;
}

int AForm::getGradeExec() const
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

void AForm::beSigned(const Bureaucrat& bureaucrat)
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

AForm& AForm::operator=(const AForm &rhs)
{
    if (this != &rhs) {
		this->isSigned = rhs.isSigned;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
    os << AForm.getName() << ", AForm grade " << AForm.getGradeSign() << " to sign and " << AForm.getGradeExec() << " to execute." << std::endl;
    return os;
}

