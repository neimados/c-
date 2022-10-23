#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	public:
		Fixed();
		Fixed(int const num);
		Fixed(float const num);
		Fixed (const Fixed& f);
		Fixed &operator=(const Fixed& f);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_fixed;
		static const int	_bits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &f);

#endif