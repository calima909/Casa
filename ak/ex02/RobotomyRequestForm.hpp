/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:05:42 by akoutsou          #+#    #+#             */
/*   Updated: 2023/10/18 16:42:52 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		virtual ~RobotomyRequestForm();
		
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
		std::string getTarget() const;
		void setTarget(std::string target);
		virtual void execute(Bureaucrat const & executor) const;
	
	private:
		std::string _target;
};

#endif
