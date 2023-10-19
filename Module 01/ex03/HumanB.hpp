#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
    private:
    std::string _name;
        Weapon *_weapon;    // pointed weapon
    public:
        HumanB(std::string name);   // Constructor
        ~HumanB();  // Destructor

        void attack();
        void setWeapon(Weapon &weapon);
};

#endif