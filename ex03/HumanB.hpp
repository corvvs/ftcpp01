#ifndef CPP01_EX03_HUMANB_HPP_
# define CPP01_EX03_HUMANB_HPP_

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB {
    public:
        HumanB(std::string name);
        void        setWeapon(Weapon* weapon);
        void        attack(void);
        Weapon*     getWeapon(void) const;
        std::string getName(void) const;

    private:
        Weapon*     weapon_;
        std::string name_;
};

#endif
