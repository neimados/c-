#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &c);
        ClapTrap &operator=(const ClapTrap &c);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    private:
        std::string     _name;
        unsigned int    _hit = 10;
        unsigned int    _energy = 10;
        unsigned int    _attack = 0;
};