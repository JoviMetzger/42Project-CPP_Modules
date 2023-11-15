#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal 
{
    public:
        Cat();                              // Default constructor
        Cat(const Cat& value);              // Copy constructor
        Cat& operator=(const Cat& value);   // Copy assignment operator
        ~Cat();                             // Destructor

};

#endif