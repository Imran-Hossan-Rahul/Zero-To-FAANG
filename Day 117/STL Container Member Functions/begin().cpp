/*

The begin() member function is used to get an iterator pointing to the first element of a container.
Unlike back() which returns a direct reference, begin() returns an ITERATOR.

HOW DOES IT RETURN AN ITERATOR? (Under the Hood):
An iterator is essentially a smart pointer. When you call `vec.begin()`, the container 
returns an iterator object that holds the memory address of the very first element (start).

Because it returns an iterator (which acts like a pointer), you MUST dereference it 
manually using the `*` operator to access or modify the actual value.
Example: 
    auto it = vec.begin();
    cout << *it; // Manually dereferencing to get the value

Supported Containers (Demonstrated here):
1. std::vector
2. std::array
3. std::list

Time Complexity:
O(1) for all the above containers. Getting the start iterator is an instantaneous operation.

Key Takeaways & Best Practices:
- Iteration: begin() is almost always used in combination with end() to loop through a container.
- Modifiability (const vs non-const): 
  By default, `begin()` returns a non-const iterator, meaning you CAN change the value it points to (e.g., *vec.begin() = 10;).
  If you have a const container (or use `cbegin()`), it returns a `const_iterator`. A `const_iterator` gives you READ-ONLY access.
  If you try to change the value of a `const_iterator` (e.g., *vec.cbegin() = 10;), the compiler will throw an error!
- Empty Containers: Calling begin() on an empty container is perfectly safe! It simply returns the same iterator as end(). 
  However, DEREFERENCING that iterator (e.g., *vec.begin()) on an empty container is Undefined Behavior and will crash.
*/

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>

using namespace std;

void demonstrateVector() {
    vector<int> vec = {10, 20, 30, 40, 50};
    
    // Get iterator to the first element
    auto it = vec.begin();
    
    // Read the first element (requires dereferencing with *)
    cout << "Vector original first element: " << *it << "\n"; // Output: Vector original first element: 10
    
    // Modify the first element by dereferencing the iterator
    *it = 99;
    cout << "Vector modified first element: " << *vec.begin() << "\n\n"; // Output: Vector modified first element: 99
}

void demonstrateArray() {
    // Fixed-size array
    array<string, 4> arr = {"Apple", "Banana", "Cherry", "Date"};
    
    // Read the first element
    cout << "Array original first element: " << *arr.begin() << "\n"; // Output: Array original first element: Apple
    
    // Modify the first element
    *arr.begin() = "Dragonfruit";
    cout << "Array modified first element: " << *arr.begin() << "\n\n"; // Output: Array modified first element: Dragonfruit
}

void demonstrateList() {
    // Doubly linked list
    list<double> lst = {3.14, 2.71, 1.618};
    
    // Read the first element
    cout << "List original first element: " << *lst.begin() << "\n"; // Output: List original first element: 3.14
    
    // Modify the first element
    *lst.begin() = 0.577;
    cout << "List modified first element: " << *lst.begin() << "\n\n"; // Output: List modified first element: 0.577
}

int main() {
    demonstrateVector();
    demonstrateArray();
    demonstrateList();
    
    /*
    CRITICAL WARNING & UNDER THE HOOD EXPLANATION:
    Dereferencing begin() on an empty container!
    
    Q1: Why does begin() == end() when a container is empty?
    A: The `end()` iterator doesn't point to the last element; it points to the memory block ONE STEP AFTER the last element.
       When a container is empty, it has 0 elements. The "first element" and the "element after the last" are logically 
       and physically the exact same memory location. Since there is no distance between them, `begin()` equals `end()`.
       
    Q2: What happens if I do `*emptyVec.begin()`?
    A: It will crash (Undefined Behavior). Because `begin()` is pointing to the same place as `end()` (which is one step 
       OUTSIDE the valid data block), trying to dereference it (`*`) means you are accessing unallocated or garbage memory.
       The operating system detects this illegal memory access and kills your program.
    
    Example of what NOT to do:
      vector<int> emptyVec;
      cout << *emptyVec.begin(); // UNDEFINED BEHAVIOR! Program will likely crash.
    
    Best Practice - Always check beforehand:
      if (!emptyVec.empty()) {
          cout << *emptyVec.begin() << endl;
      }
    */

    return 0;
}
