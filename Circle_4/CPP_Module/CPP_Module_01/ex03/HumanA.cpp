/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:55:04 by gsong             #+#    #+#             */
/*   Updated: 2023/08/15 13:40:23 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon &club) : humanName(humanName), weapon(club)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack(void) const
{
	std::cout << this->humanName << " attacks with his " << this->weapon.getType() << std::endl;
}
