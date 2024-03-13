/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:42:40 by gsong             #+#    #+#             */
/*   Updated: 2023/08/23 17:37:53 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// 기존과 같음 message만 출력 안함
Fixed::Fixed(int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fixedPointNumber = num << this->bits;
};

Fixed::Fixed(float num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->fixedPointNumber = roundf(num * (1 << this->bits));
};

Fixed::Fixed(void) : fixedPointNumber(0){
						 // std::cout << "Default constructor called" << std::endl;
					 };

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->fixedPointNumber = fixed.getRawBits();
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fixedPointNumber = fixed.getRawBits();
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
//////////////////////////////////////////////////////////////////////////////////////

// 비교 연산자
// nb1 > nb2 -> nb1.operator>(nb2)
bool Fixed::operator>(const Fixed &fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());
}
bool Fixed::operator<(const Fixed &fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());
}
bool Fixed::operator>=(const Fixed &fixed) const
{
	return (this->getRawBits() >= fixed.getRawBits());
}
bool Fixed::operator<=(const Fixed &fixed) const
{
	return (this->getRawBits() <= fixed.getRawBits());
}
bool Fixed::operator==(const Fixed &fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());
}
bool Fixed::operator!=(const Fixed &fixed) const
{
	return (this->getRawBits() != fixed.getRawBits());
}

// 사칙연산
Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed result(this->toFloat() + fixed.toFloat());
	return result;
}
Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed result(this->toFloat() - fixed.toFloat());
	return result;
}
Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed result(this->toFloat() * fixed.toFloat());
	return result;
}
Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed result(this->toFloat() / fixed.toFloat());
	return result;
}

// 증감  전위  후위  연산자  4개
Fixed &Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}
Fixed Fixed::operator++(int)
{
	const Fixed tmp(*this);
	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}
Fixed &Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}
Fixed Fixed::operator--(int)
{
	const Fixed tmp(*this);
	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}

// min, max => fixed-point number 두개 비교하는데 const일때랑 아닐때 두개씩 총 4개 구현
const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	// std::cout << "const min" << std::endl;
	if (fixed1.getRawBits() <= fixed2.getRawBits())
		return fixed1;
	else
		return fixed2;
}
Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	// std::cout << "min" << std::endl;
	if (fixed1.getRawBits() <= fixed2.getRawBits())
		return fixed1;
	else
		return fixed2;
}
const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	// std::cout << "const max" << std::endl;
	if (fixed1.getRawBits() >= fixed2.getRawBits())
		return fixed1;
	else
		return fixed2;
}
Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	// std::cout << "max" << std::endl;
	if (fixed1.getRawBits() >= fixed2.getRawBits())
		return fixed1;
	else
		return fixed2;
}

//////////////////////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &outstream, const Fixed &fixed)
{
	outstream << fixed.toFloat();
	return (outstream);
}
