/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:16:37 by gsong             #+#    #+#             */
/*   Updated: 2023/08/23 15:53:33 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointNumber = num << this->bits;
};

Fixed::Fixed(float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointNumber = roundf(num * (1 << this->bits));
};

Fixed::Fixed(void) : fixedPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointNumber = obj.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->fixedPointNumber = obj.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->fixedPointNumber);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointNumber = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->fixedPointNumber) / (1 << this->bits));
}

int Fixed::toInt(void) const
{
	return (this->fixedPointNumber / (1 << this->bits));
}

std::ostream &operator<<(std::ostream &outstream, const Fixed &fixed)
{
	outstream << fixed.toFloat();
	return (outstream);
}
