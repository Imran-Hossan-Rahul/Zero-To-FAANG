// file: capacity().cpp
// Demonstration of the STL container member function capacity().

/*
The capacity() member function returns the maximum number of elements a container 
can hold without needing to allocate new memory.

SIZE vs CAPACITY:
- size(): How many elements are currently IN the container (Data you can access).
- capacity(): How much total space is RESERVED in memory for the container right now.

Supported Containers:
1. std::vector : YES. Because vectors use dynamic arrays and grow automatically.
2. std::string : YES. Strings also pre-allocate memory to avoid frequent reallocations.
3. std::array  : NO. Arrays have a fixed size at compile-time. There is no concept of dynamic capacity.
4. std::list   : NO. Lists are node-based. They allocate exact memory for one node at a time when an element is added.

HOW IT WORKS (Under the Hood):
When a vector needs to grow because `size == capacity` and you `push_back()` a new element, it:
1. Allocates a completely new, larger block of memory on the heap.
2. Copies all existing elements to the new block.
3. Destroys the old memory block.
This is an expensive operation. To minimize how often this reallocation happens, 
vectors don't just add 1 space. Instead, `capacity()` usually grows by 1.5x or 2x (depending on the compiler).

Time Complexity:
O(1) - It simply returns the mathematical distance between internal pointers (`_M_end_of_storage - _M_start`).
*/

#include <iostream>
#include <vector>

using namespace std;

void demonstrateVectorCapacity() {
    vector<int> vec;
    
    cout << "--- Initial state ---\n";
    cout << "Size: " << vec.size() << " | Capacity: " << vec.capacity() << "\n\n"; 
    // Output: Size: 0 | Capacity: 0
    
    // Add elements and observe how capacity grows automatically
    cout << "--- Adding elements ---\n";
    for (int i = 1; i <= 5; i++) {
        vec.push_back(i * 10);
        cout << "Inserted " << (i * 10) << " => Size: " << vec.size() << " | Capacity: " << vec.capacity() << "\n";
    }
    /*
    Example Output (GCC compiler usually doubles capacity):
    Inserted 10 => Size: 1 | Capacity: 1
    Inserted 20 => Size: 2 | Capacity: 2
    Inserted 30 => Size: 3 | Capacity: 4
    Inserted 40 => Size: 4 | Capacity: 4
    Inserted 50 => Size: 5 | Capacity: 8
    */
    
    cout << "\nNotice how Capacity jumps (e.g., 0 -> 1 -> 2 -> 4 -> 8) while Size increases by 1.\n\n";
    
    // reserve(): Pre-allocating memory
    cout << "--- Using reserve() ---\n";
    vector<int> smartVec;
    smartVec.reserve(100); // We tell the vector: "Prepare 100 blocks of memory right now!"
    
    cout << "After reserve(100) -> Size: " << smartVec.size() << " | Capacity: " << smartVec.capacity() << "\n\n";
    // Output: Size: 0 | Capacity: 100
}

int main() {
    demonstrateVectorCapacity();
    
    /*
    CRITICAL BEST PRACTICE:
    If you know the approximate number of elements you are going to store in a vector, 
    ALWAYS use `reserve()` before adding elements. 
    
    Why? 
    Because it prevents the vector from constantly destroying and reallocating memory 
    behind the scenes as it grows. This drastically improves your program's performance!
    */

    return 0;
}
