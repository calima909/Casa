/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:43:56 by fchiocci          #+#    #+#             */
/*   Updated: 2023/10/25 16:43:57 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

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
    try
    {
        if (grade <= 1)
            throw GradeTooHighException();
        grade--;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << name << e.what() << std::endl;
    }
}

void Bureaucrat::decrementGrade()
{
    try
    {
        if (grade >= 150)
            throw GradeTooLowException();
        grade++;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << name << e.what() << std::endl;
    }
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


std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}


