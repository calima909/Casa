/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:03:55 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/21 13:05:51 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade >= 1 && grade <= 150)
		_grade = grade;
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName()), _grade(src.getGrade())
{

}

Bureaucrat::~Bureaucrat() 
{
	
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		_grade = rhs.getGrade();
	return(*this);
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const 
{
	return _grade;
}

void Bureaucrat::incrGrade()
{
	if (_grade > 1)
		_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrGrade()
{
	if (_grade < 150)
		_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(AForm *form)
{
	try
	{
		if (form->getSign())
		{
			std::cout << getName() << " couldn't sign " << form->getName() << " because: is already signed" << std::endl;
			return;
		}
		form->beSigned(*this);
		if (form->getGrToSig() >= getGrade())
			std::cout << getName() << " sign " << form->getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << getName() << " couldn't sign " << form->getName() << " because: " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm( AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " excecuted " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << this->getName() << " can't execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return(o);
}
