/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:24:03 by gsong             #+#    #+#             */
/*   Updated: 2023/08/15 16:01:45 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie zombie = Zombie("Foo");
	Zombie *horde = zombieHorde(3, "abc");
	for (int i = 0; i < 3; i++)
		horde[i].announce();
	zombie.announce();
	delete[] horde; // delete 말고 delete[] 로 해줘야 제대로 반환됨
	return (0);
}
