#ifndef CPP01_EX00_ZOMBIE_HPP_
# define CPP01_EX00_ZOMBIE_HPP_

# include <string>
# include <iostream>
# include <sstream>

class Zombie {
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);
        void        announce(void) const;
        std::string getName(void) const;
        void        setName(std::string name);

    private:
        std::string name_;
};

#endif
