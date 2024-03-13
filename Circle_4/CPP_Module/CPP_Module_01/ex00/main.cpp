/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:31:44 by gsong             #+#    #+#             */
/*   Updated: 2023/08/15 15:58:31 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie stack = Zombie("stack1");
	Zombie *heap = newZombie("heap");
	randomChump("stack2");

	stack.announce();
	heap->announce();
	delete heap;

	return 0;
}
