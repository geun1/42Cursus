/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:08:48 by gsong             #+#    #+#             */
/*   Updated: 2023/08/15 14:05:40 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_H_
#define _WEAPON_H_

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string type;

public:
	Weapon(std::string type);
	~Weapon();
	const std::string &getType(void) const;
	void setType(const std::string type);
};

#endif
