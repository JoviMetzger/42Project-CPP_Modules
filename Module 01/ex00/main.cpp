#include "Zombie.hpp"

int main()
{
    // Create a heap zombie and announce it and destroy it
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    // Create and announce a stack zombie
    randomChump("stackZombie");

    return 0;

}


/*

Allocate on the Stack:

Short-Lived Objects: If the zombies have a limited and predictable lifetime within a well-defined scope, allocating them on the stack is a good choice. When the stack frame for the function ends, the object is automatically destroyed.
Simplicity: Stack allocation is simple and efficient. You don't need to manage memory explicitly, and the objects are automatically destroyed when they go out of scope.
Lower Overhead: Stack allocation typically has lower memory overhead compared to heap allocation, as it doesn't involve memory management overhead like allocation and deallocation.
Deterministic Destruction: Stack-allocated objects are destroyed in a deterministic manner as they go out of scope, which can be important for resource management.

Allocate on the Heap:

Dynamic Lifetime: If you need the zombies to persist beyond the scope of the function where they are created, heap allocation is necessary. Heap-allocated objects have a dynamic lifetime and can exist until explicitly deallocated.
Sharing Objects: If multiple parts of your program need to access the same zombies (shared state), you should allocate them on the heap, allowing multiple parts of the program to access and manipulate the same object.
Dynamic Sizing: When the size of the object is not known at compile time, heap allocation is the only viable option. The heap can provide memory allocation for objects of varying sizes.
Avoiding Stack Overflow: In situations where you might run into a stack overflow due to deeply nested or recursive function calls, heap allocation is a safer option since the heap typically has more memory available.
Complex Ownership and Lifetime: For more complex ownership and lifetime scenarios, where objects may be transferred between different parts of the program, heap allocation offers more flexibility and control.

In summary, stack allocation is preferred for objects with a predictable and short-lived scope, while heap allocation is suitable for objects with dynamic lifetimes, complex ownership scenarios, and the need for long-term persistence. The choice between stack and heap allocation should align with the specific requirements of your program and the intended use of the objects.


heapZombie: The heapZombie is created on the heap using dynamic memory allocation, typically through the new operator in C++. This means that the memory for the heapZombie object is allocated on the heap, and you need to manually deallocate it when you're done with it using delete. Heap-allocated objects have a longer lifetime and exist until explicitly freed by the programmer. In your code, you create a heapZombie with newZombie, and you later delete it with delete heapZombie.

stackZombie: The stackZombie is created on the stack. Stack-allocated objects are automatically managed by the program's execution stack. They have a shorter lifetime and are typically limited to the scope in which they are defined. When the scope ends (e.g., when the function returns), the stack-allocated objects are automatically destroyed. In your code, you create a stackZombie with randomChump, and it is automatically destroyed when the function randomChump ends.

The key differences are:

Memory Management: For heapZombie, you're responsible for both allocation and deallocation of memory. For stackZombie, memory is managed automatically by the program.

Lifetime: heapZombie can persist beyond the function or scope in which it was created until explicitly deleted. stackZombie exists only within the scope where it's declared.

Risk: Improper handling of heap-allocated objects can lead to memory leaks (not releasing memory) or dangling pointers (using memory after it's been freed). Stack-allocated objects are automatically destroyed when their scope ends, reducing the risk of such issues.

In your code, the main difference between heapZombie and stackZombie is that heapZombie is allocated on the heap and must be manually deleted, while stackZombie is automatically destroyed when the randomChump function returns.
*/