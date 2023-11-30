#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

/* NOTE:
 *  - ICharacter is the interface of Character
 *  - That's why ICharacter has no 'own functions', it inherits them from Character
 */
class   Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *(_inventoryMateria[4]);
    public:
        Character();					// Default constructor
		Character(const Character& value);			// Copy constructor
		Character& operator=(const Character& value);	// Copy assignment operator
		~Character();				// Destructor

        Character(std::string const name);

        // Member functions
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        AMateria    *getMateria(int i);

};

#endif