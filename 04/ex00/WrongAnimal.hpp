#pragma once

#include <iostream>

class WrongAnimal{
    public:
        WrongAnimal();
        WrongAnimal(std::string name);
        WrongAnimal(const WrongAnimal &a);
        WrongAnimal &operator=(const WrongAnimal &a);
        ~WrongAnimal();

        void        makeSound() const;
        std::string getType() const;

    protected:
        std::string type;
};