/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:41:24 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/14 15:41:46 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int grtosig, int grtoex) : _name(name), _grade_to_sign(grtosig), _grade_to_exec(grtoex)
{
	if ((grtosig >= 1 && grtosig <= 150) && (grtoex >= 1 && grtoex <= 150))
		_signed = false;
	else if (grtosig < 1 || grtoex < 1)
		throw AForm::GradeTooHighException();
	else
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src.getName()), _grade_to_sign(src.getGrToSig()), _grade_to_exec(src.getGrToEx())
{
	_signed = src.getSign();
}

AForm::~AForm() 
{
	
}


AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		_signed = rhs.getSign();
	return(*this);
}

std::string AForm::getName() const
{
	return _name;
}

int AForm::getGrToEx() const 
{
	return _grade_to_exec;
}

int AForm::getGrToSig() const 
{
	return _grade_to_sign;
}

bool AForm::getSign() const
{
	return(_signed);
}

void AForm::beSigned(Bureaucrat stalin)
{
	if (stalin.getGrade() <= getGrToSig() )
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
{
	o  << "Name: " << rhs.getName() << std::endl;
	o  << "Grade to Sign: " << rhs.getGrToSig() << std::endl;
	o  << "Grade to exec: " << rhs.getGrToEx() << std::endl;
	return(o);
}
