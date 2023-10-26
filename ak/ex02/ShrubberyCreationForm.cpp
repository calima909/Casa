/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:05:45 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/18 19:19:21 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src) : AForm(src.getName(), src.getGrToSig(), src.getGrToEx())
{
	this->_target = src.getTarget();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
		this->setTarget(rhs.getTarget());
	return(*this);
}

std::string ShrubberyCreationForm::getTarget()const
{
	return _target;
}

void ShrubberyCreationForm::setTarget(std::string target)
{
	_target = target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= getGrToEx() && getSign())
	{
		std::ofstream ofs((this->getTarget() + "_shrubbery").c_str());
		ofs << "my-app/\n├─ node_modules/\n├─ public/\n├─ favicon.ico\n│  ├─ index.html\n│  ├─ robots.txt\n├─ src/\n│  ├─ README.md\n│  ├─ index.css\n│  ├─ index.js\n├─ .gitignore\n├─ package.json\n"<<"\n";
		ofs << std::endl;
		for (int i = 0; i < 3; i++)
		{
			ofs << std::endl;
			ofs << "   ^" << std::endl;
			ofs << "  ^^^" << std::endl;
			ofs << " ^^^^^" << std::endl;
			ofs << "^^^^^^^" << std::endl;
			ofs << "   |" << std::endl;
			ofs << std::endl;
		}
		ofs.close();
	}
	else if (!getSign())
		throw ShrubberyCreationForm::NotSignedException();
	else
		throw ShrubberyCreationForm::GradeTooLowException();
}
