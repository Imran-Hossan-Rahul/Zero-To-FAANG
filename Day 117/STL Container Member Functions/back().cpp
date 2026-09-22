/*

The back() member function is used to access the last element of a container.
It returns a reference (or const_reference) to the very last element.

HOW DOES IT RETURN A REFERENCE? (Under the Hood):
When you call `vec.back()`, you don't get a memory address (pointer). You get the actual element.
Internally, the back() function is usually implemented like this:
    
    T& back() {
        return *(end() - 1); 
    }

Notice the `*` (dereference operator). The function calculates the memory address of the last 
element (`end() - 1`), dereferences it with `*`, and returns it as a C++ Reference (`T&`). 
Because the function's return type is defined as a reference (`T&`), C++ automatically binds 
the returned value to its original memory location. That is why you don't need to manually 
dereference it again in your code.

Supported Containers (Demonstrated here):
1. std::vector
2. std::array
3. std::list

Time Complexity:
O(1) for all the above containers. Accessing the last element is an instantaneous operation.

Key Takeaways & Best Practices:
- Modifiability: Because back() returns a reference, you can use it to directly change the value of the last element.
- Undefined Behavior Risk: Calling back() on an EMPTY container leads to undefined behavior (often a crash/segmentation fault). 
  Always ensure the container is not empty (e.g., using .empty()) before calling .back().
- To remove the last element, use pop_back() instead (supported by vector and list, but not array).

*/

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>

using namespace std;

void demonstrateVector() {
    vector<int> vec = {10, 20, 30, 40, 50};
    
    // Read the last element
    cout << "Vector original last element: " << vec.back() << "\n"; // Output: Vector original last element: 50
    
    // Modify the last element via the reference returned by back()
    vec.back() = 99;
    cout << "Vector modified last element: " << vec.back() << "\n\n"; // Output: Vector modified last element: 99
}

void demonstrateArray() {
    // Fixed-size array
    array<string, 4> arr = {"Apple", "Banana", "Cherry", "Date"};
    
    // Read the last element
    cout << "Array original last element: " << arr.back() << "\n"; // Output: Array original last element: Date
    
    // Modify the last element
    arr.back() = "Dragonfruit";
    cout << "Array modified last element: " << arr.back() << "\n\n"; // Output: Array modified last element: Dragonfruit
}

void demonstrateList() {
    // Doubly linked list
    list<double> lst = {3.14, 2.71, 1.618};
    
    // Read the last element
    cout << "List original last element: " << lst.back() << "\n"; // Output: List original last element: 1.618
    
    // Modify the last element
    lst.back() = 0.577;
    cout << "List modified last element: " << lst.back() << "\n\n"; // Output: List modified last element: 0.577
}

int main() {
    demonstrateVector();
    demonstrateArray();
    demonstrateList();
    
    /*
    CRITICAL WARNING:
    Never call back() on an empty container!
    
    Example of what NOT to do:
      vector<int> emptyVec;
      cout << emptyVec.back(); // UNDEFINED BEHAVIOR! Program will likely crash.
    
    Best Practice - Always check beforehand:
      if (!emptyVec.empty()) {
          cout << emptyVec.back() << endl;
      } else {
          cout << "Container is empty!" << endl;
      }
    */

    return 0;
}
