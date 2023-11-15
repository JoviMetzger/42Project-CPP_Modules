#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();                               // Default constructor
        Animal(const Animal& value);            // Copy constructor
        Animal& operator=(const Animal& value); // Copy assignment operator
        ~Animal();                              // Destructor

        // Member Functions
        void makeSound() const;

        std::string getType() const;
};

#endif