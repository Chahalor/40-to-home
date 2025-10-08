#pragma once

#include "all.hpp"

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed(/* args */);
		~Fixed();
		Fixed&	operator=(const Fixed &other);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};
