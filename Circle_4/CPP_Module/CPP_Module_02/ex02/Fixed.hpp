#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int fixedPointNumber;
	static const int bits = 8;

public:
	Fixed();
	Fixed(int num);
	Fixed(float num);
	Fixed(const Fixed &obj);
	~Fixed();
	Fixed &operator=(const Fixed &obj);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	// 비교 연산자
	bool operator>(const Fixed &fixed) const;
	bool operator<(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;
	bool operator!=(const Fixed &fixed) const;

	// 사칙연산
	Fixed operator+(const Fixed &fixed) const;
	Fixed operator-(const Fixed &fixed) const;
	Fixed operator*(const Fixed &fixed) const;
	Fixed operator/(const Fixed &fixed) const;

	// 증감  전위  후위  연산자  4개
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	// min, max => fixed-point number 두개 비교하는데 const일때랑 아닐때 두개씩 총 4개 구현
	static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
	static Fixed &min(Fixed &fixed1, Fixed &fixed2);
	static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
	static Fixed &max(Fixed &fixed1, Fixed &fixed2);
};

std::ostream &operator<<(std::ostream &outstream, const Fixed &fixed);

#endif
