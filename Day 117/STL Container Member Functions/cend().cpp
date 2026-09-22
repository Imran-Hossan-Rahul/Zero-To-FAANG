// file: cend().cpp
// Demonstration of the STL container member function cend().

/*
The cend() member function (which stands for "const end") returns a CONSTANT ITERATOR 
(const_iterator) pointing to the memory location exactly ONE STEP AFTER the last element.

end() vs cend() - THE DIFFERENCE:
- end() returns a regular iterator pointing to one past the last element.
- cend() returns a const_iterator pointing to one past the last element.

WHAT IS IT USED FOR?
Just like `end()`, `cend()` does NOT point to a valid element, so you can NEVER dereference it 
(e.g., `*vec.cend()` will crash your program). 
Its sole purpose is to act as a BOUNDARY or STOPPING CONDITION when iterating through a 
container with `cbegin()`. 

Why use cend() instead of end()? (Best Practice)
When you are traversing a container just to read data (using `cbegin()`), you should use `cend()` 
as the stopping condition to maintain strict "Const Correctness". Mixing `const_iterator` (from cbegin) 
and regular `iterator` (from end) in a loop condition can sometimes lead to type mismatch warnings 
or errors in older C++ standards. It is a professional habit to pair `cbegin()` with `cend()`.

Supported Containers (Demonstrated here):
1. std::vector
2. std::array
3. std::list

Time Complexity:
O(1) for all the above containers. Calculating the end const_iterator is an instantaneous operation.
*/

#include <iostream>
#include <vector>
#include <array>
#include <list>

using namespace std;

void demonstrateVectorCend() {
    vector<int> vec = {10, 20, 30, 40, 50};
    
    cout << "--- std::vector::cend() ---\n";
    cout << "Vector elements via const_iterator: ";
    
    // Using cbegin() and cend() together for read-only traversal
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
        cout << *it << " ";
        
        // ❌ WHAT YOU CANNOT DO:
        // *it = 99; // ERROR! Cannot modify because 'it' is a const_iterator
    }
    cout << "\n\n";
    
    /*
    ❌ CRITICAL WARNING:
    cout << *vec.cend(); // UNDEFINED BEHAVIOR! Program will crash!
    Never try to read the value at cend() because it points to unallocated/garbage memory.
    */
}

void demonstrateArrayCend() {
    array<int, 3> arr = {100, 200, 300};
    
    cout << "--- std::array::cend() ---\n";
    cout << "Array elements: ";
    for (auto it = arr.cbegin(); it != arr.cend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";
}

void demonstrateListCend() {
    list<double> lst = {1.1, 2.2, 3.3};
    
    cout << "--- std::list::cend() ---\n";
    cout << "List elements: ";
    for (auto it = lst.cbegin(); it != lst.cend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";
}

int main() {
    demonstrateVectorCend();
    demonstrateArrayCend();
    demonstrateListCend();
    
    /*
    Summary: 
    Whenever you want to write a loop that only reads data and doesn't modify it, 
    always pair `cbegin()` with `cend()`. It makes your code safer, more professional, 
    and easier for other developers to understand your exact intentions!
    */

    return 0;
}
