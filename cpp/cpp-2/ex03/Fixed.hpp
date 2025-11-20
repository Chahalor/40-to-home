#pragma once

#include "all.hpp"

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &_other);
		~Fixed();

		Fixed				&operator=(const Fixed &other);
		bool				operator>(const Fixed &other);
		bool				operator<(const Fixed &other);
		bool				operator>=(const Fixed &other);
		bool				operator<=(const Fixed &other);
		bool				operator==(const Fixed &other);
		bool				operator!=(const Fixed &other);
		Fixed				operator+(const Fixed &other) const;
		Fixed				operator-(const Fixed &other) const;
		Fixed				operator*(const Fixed &other) const;
		Fixed				operator/(const Fixed &other) const;
		Fixed				operator++(int value);
		Fixed				operator--(int value);
		Fixed				operator++();
		Fixed				operator--();
		int					getRawBits(void) const;
		void				setRawBits(const int raw);

		float				toFloat(void) const;
		int					toInt(void) const;

		static Fixed		&min(Fixed &f1, Fixed &f2);
		static Fixed const&	min(Fixed const& f1, Fixed const& f2);
		static Fixed		&max(Fixed &f1, Fixed &f2);
		static Fixed const&	max(Fixed const& f1, Fixed const& f2);
		static Fixed		abs(const Fixed &f);
};

std::ostream	&operator<<(std::ostream &os, const Fixed &f);