/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:31:16 by gsong             #+#    #+#             */
/*   Updated: 2023/08/15 13:40:35 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HUMAN_A_H_
#define _HUMAN_A_H_

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	std::string humanName;
	Weapon &weapon;

public:
	HumanA(std::string humanName, Weapon &club);
	~HumanA();
	void attack(void) const;
};

#endif
