/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:36:52 by fchiocci          #+#    #+#             */
/*   Updated: 2023/10/26 17:04:33 by fchiocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#   define SHRUBBERYCREATIONFORM_HPP

#   include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
        
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm &toCopy);
        ~ShrubberyCreationForm();
        
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &toCopy);
        
        std::string getTarget() const;
        void setTarget(const std::string &target);
        void virtual execute(Bureaucrat const & executor) const;
};

#endif