#pragma once

#include <iostream>

class AAnimal{
    public:
        AAnimal();
        AAnimal(std::string name);
        AAnimal(const AAnimal &a);
        AAnimal &operator=(const AAnimal &a);
        virtual ~AAnimal();

        virtual void            makeSound() const = 0;
        virtual std::string     getType() const;

    protected:
        std::string type;
};