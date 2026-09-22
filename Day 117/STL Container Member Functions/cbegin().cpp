// file: cbegin().cpp
// Demonstration of the STL container member function cbegin().

/*
The cbegin() member function (which stands for "const begin") returns a CONSTANT ITERATOR 
(const_iterator) pointing to the first element of a container.

begin() vs cbegin() - THE CORE DIFFERENCE:
- begin() returns a regular iterator. You can use it to READ and MODIFY the element it points to.
- cbegin() returns a const_iterator. You can only use it to READ the element. 
  Any attempt to modify the element through a const_iterator will result in a strict COMPILE-TIME ERROR!

Why should we use cbegin()? (Best Practice & Professional Code)
1. Readability: It immediately tells anyone reading your code that "I only intend to read this data, not modify it."
2. Safety: It prevents accidental bugs where you might unintentionally change a value while looping or accessing data.
3. Const Correctness: If a container itself is marked as `const` (e.g., passed to a function as a `const vector<int>&`), 
   you are forced to interact with it using constant iterators. `cbegin()` makes this explicit.

Supported Containers (Demonstrated here):
1. std::vector
2. std::array
3. std::list

Time Complexity:
O(1) for all the above containers. Getting the start const_iterator is an instantaneous operation.

HOW IT WORKS (Under the Hood):
When you call `cbegin()`, it works exactly like `begin()`, pointing to the `_M_start` of the 
allocated memory. It takes up no extra memory. The ONLY difference is at the compiler level. 
The C++ compiler strictly enforces a rule that the memory address held by this iterator is 
treated as READ-ONLY (`const T*`). You can look at the house, but you can't change the furniture!
*/

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>

using namespace std;

void demonstrateVectorCbegin() {
    vector<int> vec = {10, 20, 30, 40, 50};
    
    // Get const_iterator to the first element
    auto it = vec.cbegin();
    
    cout << "--- std::vector::cbegin() ---\n";
    // READ the first element (Safe and Allowed)
    cout << "Vector first element: " << *it << "\n"; // Output: Vector first element: 10
    
    // ❌ WHAT YOU CANNOT DO:
    // *it = 99; // If you uncomment this line, the code WILL NOT COMPILE!
    
    // Using cbegin() with cend() in a loop (Best Practice for read-only loops)
    cout << "Vector elements via const_iterator: ";
    for (auto const_it = vec.cbegin(); const_it != vec.cend(); ++const_it) {
        cout << *const_it << " "; // Output: 10 20 30 40 50
    }
    cout << "\n\n";
}

void demonstrateArrayCbegin() {
    array<string, 4> arr = {"Apple", "Banana", "Cherry", "Date"};
    
    cout << "--- std::array::cbegin() ---\n";
    cout << "Array first element: " << *arr.cbegin() << "\n"; // Output: Array first element: Apple
    
    // ❌ ERROR Example:
    // *arr.cbegin() = "Dragonfruit"; // COMPILER ERROR!
    cout << "\n";
}

void demonstrateListCbegin() {
    list<double> lst = {3.14, 2.71, 1.618};
    
    cout << "--- std::list::cbegin() ---\n";
    cout << "List first element: " << *lst.cbegin() << "\n"; // Output: List first element: 3.14
    
    // ❌ ERROR Example:
    // *lst.cbegin() = 0.577; // COMPILER ERROR!
    cout << "\n";
}

// Example showing why cbegin() is heavily used in professional codebases
void printVector(const vector<int>& v) {
    cout << "--- Const Function Parameter Demo ---\n";
    // Because 'v' is a CONST reference, we promise not to change it.
    // Using cbegin() clearly shows our intent to only read the data.
    cout << "Printing const vector: ";
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

int main() {
    demonstrateVectorCbegin();
    demonstrateArrayCbegin();
    demonstrateListCbegin();
    
    vector<int> myVec = {100, 200, 300};
    printVector(myVec);
    
    /*
    Empty Containers & cbegin():
    Just like `begin()`, calling `cbegin()` on an empty container is perfectly safe! 
    It simply returns the same const_iterator as `cend()`.
    
    But remember, DEREFERENCING it (e.g., `*emptyVec.cbegin()`) on an empty container 
    will still result in a crash (Undefined Behavior)!
    */

    return 0;
}
