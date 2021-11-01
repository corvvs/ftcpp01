#ifndef CPP01_EX03_HUMANA_HPP_
# define CPP01_EX03_HUMANA_HPP_

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA {
    public:
        HumanA(std::string name, Weapon& weapon);
        void        attack(void);

    private:
        Weapon&     weapon_;
        std::string name_;
};

#endif
