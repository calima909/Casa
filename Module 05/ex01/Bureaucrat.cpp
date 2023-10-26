/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:44:24 by fchiocci          #+#    #+#             */
/*   Updated: 2023/10/25 16:44:25 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    std::cout << "Constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &toCopy) : name(toCopy.name)
{
    std::cout << "Copy constructor called" << std::endl;
    this->grade = toCopy.grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}
int Bureaucrat::getGrade() const
{
    return grade;
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

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

void Bureaucrat::signForm(Form &form)
{
    try
    {
        if (form.getIsSigned() == true)
        {
            std::cout << name << " couldn't sign " << form.getName() << " because form is yet signed" << std::endl << std::flush;
        }        
        else if (form.getGradeExec() < grade)
        {
            std::cout << name << " couldn't sign " << form.getName() << " because required grade exec is too low" << std::endl << std::flush;
            throw GradeTooLowException();
        }
        else
            form.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Expection: " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
