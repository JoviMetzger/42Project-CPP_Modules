#include "Zombie.hpp"

int main()
{

    // Create a heap zombie and announce it and destroy it
    std::cout << L_BLUE << "HEAP" << RESET << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;


    // Create and announce a stack zombie
    std::cout << L_BLUE << "\n\nStack" << RESET << std::endl;
    randomChump("StackZombie");

    return 0;

}


/*
 * Allocate on the Heap:
 *  - The heapZombie is created on the heap using dynamic memory allocation, 
 *    typically through the new operator in C++. 
 *  - This means that the memory for the heapZombie object is allocated on the heap, 
 *    and you need to manually deallocate it when you're done with it using delete. 
 *  - Heap-allocated objects have a longer lifetime and exist 
 *    until explicitly freed by the programmer.
 *
 * Allocate on the Stack:
 *  - Stack-allocated objects are automatically managed by the program's execution stack. 
 *  - They have a shorter lifetime and are typically limited to the scope in which they are defined. 
 *  - When the scope ends (e.g., when the function returns), 
 *    the stack-allocated objects are automatically destroyed. 
 */