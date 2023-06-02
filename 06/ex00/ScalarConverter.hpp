#pragma once

# include <iostream>
# include <cstdlib>

class ScalarConverter {
    public:

        static void    convert(std::string &input);

        static int    check(std::string &input);

        static void    toChar(std::string &input);
        static void    convertChar(std::string &input);
        
        static void    toInt(std::string &input, int i);
        static void    convertInt(std::string &input, int i);

        static void    toFloat(std::string &input, int i);
        static void    convertFloat(std::string &input, int i);

        static void    toDouble(std::string &input, int i);
        static void    convertDouble(std::string &input, int i);

        class NonDisplayable : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class Impossible : public std::exception{
            public:
                virtual const char* what() const throw();
        };

    private:
        ScalarConverter();
        ScalarConverter(std::string &str);
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &conv);
        ScalarConverter &operator=(const ScalarConverter &conv);

        // std::string _str;
        // double      _d;  
        // bool        _possible;
        // int         _count;
        // int         _dot;
};
