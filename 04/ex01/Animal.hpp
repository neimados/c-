#pragma once

#include <iostream>

class Animal{
    public:
        Animal();
        Animal(std::string name);
        Animal(const Animal &a);
        Animal &operator=(const Animal &a);
        virtual ~Animal();

        virtual void        makeSound() const;
        std::string getType() const;

    protected:
        std::string type;
};