#ifndef CPP01_EX00_ZOMBIE_HPP_
# define CPP01_EX00_ZOMBIE_HPP_

# include <string>
# include <iostream>
# include <sstream>

class Zombie {
    public:
        Zombie(std::string name);
        ~Zombie(void);
        void        announce(void);

    private:
        Zombie(void);
        std::string name_;
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif
