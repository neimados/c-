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

		bool operator>(const Fixed& f) const;
		bool operator<(const Fixed& f) const;
		bool operator>=(const Fixed& f) const;
		bool operator<=(const Fixed& f) const;
		bool operator==(const Fixed& f) const;
		bool operator!=(const Fixed& f) const;

		Fixed operator+(const Fixed& f);
		Fixed operator-(const Fixed& f);
		Fixed operator*(const Fixed& f);
		Fixed operator/(const Fixed& f);
		
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);

		static Fixed &min(Fixed &ref1, Fixed &ref2);
		static Fixed const &min(Fixed const &ref1, Fixed const &ref2);
		static Fixed &max(Fixed &ref1, Fixed &ref2);
		static Fixed const &max(Fixed const &ref1, Fixed const &ref2);

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