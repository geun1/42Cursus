/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:06:21 by gsong             #+#    #+#             */
/*   Updated: 2023/08/15 14:04:32 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string humanName) : humanName(humanName), weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack(void) const
{
	if (!this->weapon)
		std::cout << this->humanName << " doesn't have weapon" << std::endl;
	else
		std::cout << this->humanName << " attacks with his " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &club)
{
	this->weapon = &club;
}
