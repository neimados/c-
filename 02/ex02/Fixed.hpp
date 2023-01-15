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

		bool operator>(const Fixed& f);
		bool operator<(const Fixed& f);
		bool operator>=(const Fixed& f);
		bool operator<=(const Fixed& f);
		bool operator==(const Fixed& f);
		bool operator!=(const Fixed& f);

		Fixed operator+(const Fixed& f);
		Fixed operator-(const Fixed& f);
		Fixed operator*(const Fixed& f);
		Fixed operator/(const Fixed& f);
		
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed& min(Fixed& f1, Fixed& f2);
		static const Fixed& min(const Fixed& f1, const Fixed& f2);
		static Fixed& max(Fixed& f1, Fixed& f2);
		static const Fixed& max(const Fixed& f1, const Fixed& f2);

	private:
		int					_fixed;
		static const int	_bits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &f);

#endif