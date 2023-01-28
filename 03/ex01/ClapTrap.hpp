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

    protected:
        std::string     _name;
        unsigned int    _hit;
        unsigned int    _energy;
        unsigned int    _attack;
};

#endif