/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:23:55 by gsong             #+#    #+#             */
/*   Updated: 2023/08/15 15:06:52 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " Zombie constructor" << std::endl;
}
Zombie::~Zombie()
{
	std::cout << this->_name << " Zombie destuctor" << std::endl;
}
void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string name, int i)
{
	std::stringstream ss;
	ss << name << i;
	this->_name = ss.str();
}
