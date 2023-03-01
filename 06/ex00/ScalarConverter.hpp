#pragma once

# include <iostream>
# include <cstdlib>

class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(std::string &str);
        ScalarConverter(const ScalarConverter &conv);
        ScalarConverter &operator=(const ScalarConverter &conv);
        ~ScalarConverter();

        void    check();
        void    convert();

        void    toChar() const;
        void    convertChar() const;
        
        void    toInt() const;
        void    convertInt() const;

        void    toFloat() const;
        void    convertFloat() const;

        void    toDouble() const;
        void    convertDouble() const;

        class NonDisplayable : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class Impossible : public std::exception{
            public:
                virtual const char* what() const throw();
        };

    private:
        std::string _str;
        double      _d;  
        bool        _possible;
        int         _count;
        int         _dot;
};
