/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:05:12 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/18 19:19:29 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentiaPardon", 25, 5), _target(target)
{
	
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src) : AForm(src.getName(), src.getGrToSig(), src.getGrToEx())
{
	this->_target = src.getTarget();
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
		this->setTarget(rhs.getTarget());
	return(*this);
}

std::string PresidentialPardonForm::getTarget()const
{
	return _target;
}

void PresidentialPardonForm::setTarget(std::string target)
{
	_target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= getGrToEx() && getSign())
		std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else if (!getSign())
		throw PresidentialPardonForm::NotSignedException();
	else
		throw PresidentialPardonForm::GradeTooLowException();
}
