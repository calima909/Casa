/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:41:35 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/14 16:01:25 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include"Bureaucrat.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>
# include <time.h>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _grade_to_sign;
		const int _grade_to_exec;

	public:
		AForm(std::string name, int grtosig, int grtoex);
		AForm(const AForm &src);
		virtual ~AForm();
		
		AForm &operator=(const AForm &rhs);
		std::string getName() const;
		bool getSign() const;
		int getGrToSig() const;
		int getGrToEx() const;
		void beSigned(Bureaucrat stalin);
		
		virtual void execute(Bureaucrat const & executor) const = 0;
	
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "Grade too High"; }
	};
		
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "Grade too low"; }
	};
	class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "Form is not signed"; }
	};
};

std::ostream &operator<<(std::ostream &o, const AForm &rhs);

#endif
