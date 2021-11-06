#ifndef CPP01_EX03_WEAPON_HPP_
# define CPP01_EX03_WEAPON_HPP_

# include <string>

class Weapon {
    public:
        Weapon(std::string type);
        const std::string&  getType(void) const ;
        void                setType(std::string type);
    private:
        std::string         type_;
};

#endif
