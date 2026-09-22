// file: crend().cpp
// Demonstration of the STL container member function crend() and crbegin().

/*
The crend() member function stands for "const reverse end". 
It returns a CONSTANT REVERSE ITERATOR (const_reverse_iterator) pointing to the 
theoretical memory location exactly ONE STEP BEFORE the very first element.

WHAT IS A REVERSE ITERATOR?
Instead of moving forward (from start to finish), a reverse iterator moves backward 
(from finish to start). Magically, when you do `++it` on a reverse iterator, it actually 
moves to the PREVIOUS element in memory!

crbegin() vs crend() - THE REVERSE PAIR
- crbegin(): "Const Reverse Begin". Points to the VERY LAST element. This is where reverse traversal starts.
- crend(): "Const Reverse End". Conceptually represents the position ONE STEP BEFORE THE FIRST element. This is where reverse traversal stops. (See "Under the Hood" below to see why it doesn't physically point there).

HOW IT WORKS UNDER THE HOOD (The Magic of Reverse Iterators):

To understand this without getting confused, you need to know one GOLDEN RULE: 
A reverse iterator ALWAYS physically stores a pointer that is ONE STEP AHEAD of the element it conceptually represents!

Let's break it down:

1. How `crbegin()` works:
   - CONCEPTUAL: It represents the VERY LAST element (e.g., 50).
   - PHYSICAL (Under the hood): It actually stores the `cend()` pointer (which is one step AFTER 50).
   - DEREFERENCING (`*`): When you do `*crbegin()`, C++ takes its physical pointer (`cend()`), steps back one position (`--`), and reads the value (50). 

2. How `crend()` works:
   - CONCEPTUAL: It represents the boundary ONE STEP BEFORE the FIRST element (where the loop stops).
   - PHYSICAL (Under the hood): It actually stores the `cbegin()` pointer (which is the FIRST element itself, e.g., 10).
   - DEREFERENCING (`*`): If you try to do `*crend()`, it will take its physical pointer (`cbegin()`), step back one position (`--`), and try to read the garbage memory BEFORE the array. That is exactly why `*crend()` crashes!

3. How the Loop Stops Safely:
   When you write a loop: `for (auto it = vec.crbegin(); it != vec.crend(); ++it)`
   - The loop simply compares the PHYSICAL pointers under the hood.
   - It checks: "Is my current physical pointer equal to `cbegin()`?"
   - When the physical pointer reaches `cbegin()`, the loop STOPS immediately! It never actually dereferences it, so it never reads the garbage memory.

This genius design means C++ NEVER has to store an illegal memory address (like an address before the array). It uses valid boundary addresses (`cend` and `cbegin`), but shifts them by 1 step when you actually want to read the data!

WHY CONST REVERSE? (Best Practice)
Just like `cbegin()` and `cend()`, the "c" guarantees that you are only READING the data. 
The C++ compiler will strictly forbid any attempts to modify the elements through these iterators.

Supported Containers (Demonstrated here):
1. std::vector
2. std::array
3. std::list
(Note: Forward-only containers like `std::forward_list` do not support reverse iterators).

Time Complexity:
O(1) - Calculating the const reverse iterator is an instantaneous operation.
*/

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>

using namespace std;

void demonstrateVectorCrend() {
    vector<int> vec = {10, 20, 30, 40, 50};
    
    cout << "--- std::vector::crend() ---\n";
    cout << "Vector elements in REVERSE (Read-Only): ";
    
    // Reverse traversal using crbegin() and crend()
    for (auto it = vec.crbegin(); it != vec.crend(); ++it) {
        cout << *it << " "; // Output: 50 40 30 20 10
        
        // ❌ WHAT YOU CANNOT DO:
        // *it = 99; // ERROR! Cannot modify because it's a const_reverse_iterator
    }
    cout << "\n\n";
    
    /*
    ❌ CRITICAL WARNING: WHY DOES *vec.crend() CRASH?
    cout << *vec.crend(); // UNDEFINED BEHAVIOR! Program will crash!
    
    Recall the "Golden Rule" from above:
    When you do `*crend()`, C++ takes its physical pointer (which is `cbegin()`), 
    steps BACK one position (`--`), and tries to read the value. 
    
    But `cbegin()` is already the very first element! Stepping back from it takes you 
    to the garbage memory BEFORE the array, which your program does not own. 
    Trying to read that illegal memory causes a crash (Segmentation Fault).
    */
}

void demonstrateArrayCrend() {
    array<string, 3> arr = {"Apple", "Banana", "Cherry"};
    
    cout << "--- std::array::crend() ---\n";
    cout << "Array elements in REVERSE: ";
    for (auto it = arr.crbegin(); it != arr.crend(); ++it) {
        cout << *it << " "; // Output: Cherry Banana Apple
    }
    cout << "\n\n";
}

void demonstrateListCrend() {
    list<double> lst = {1.1, 2.2, 3.3};
    
    cout << "--- std::list::crend() ---\n";
    cout << "List elements in REVERSE: ";
    for (auto it = lst.crbegin(); it != lst.crend(); ++it) {
        cout << *it << " "; // Output: 3.3 2.2 1.1
    }
    cout << "\n\n";
}

int main() {
    demonstrateVectorCrend();
    demonstrateArrayCrend();
    demonstrateListCrend();
    
    /*
    Summary: 
    When you need to read a container from back-to-front (reverse order) without modifying 
    any data, the absolute safest and most professional way is to use a loop that starts 
    at `crbegin()` and stops at `crend()`.
    */

    return 0;
}
