/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:31:16 by gsong             #+#    #+#             */
/*   Updated: 2023/08/15 13:45:55 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMAN_B_H_
#define _HUMAN_B_H_

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
	std::string humanName;
	Weapon *weapon;

public:
	HumanB(std::string humanName);
	~HumanB();
	void attack(void) const;
	void setWeapon(Weapon &weapon);
};

#endif
