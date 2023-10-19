#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon &_weapon;    // reference weapon
    public:
        HumanA(std::string name, Weapon &weapon);   // Constructor
        ~HumanA();  // Destructor

        void attack();
        void setWeapon(Weapon &weapon);
};

#endif