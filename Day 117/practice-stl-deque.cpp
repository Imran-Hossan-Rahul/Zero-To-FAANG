/**
 * @file practice-stl-deque.cpp
 * @brief Comprehensive Guide to std::deque in C++ STL
 * 
 * WHAT IS A DEQUE?
 * `std::deque` stands for "Double-Ended Queue" (pronounced as "deck").
 * It is a sequence container that allows fast insertion and deletion at BOTH 
 * the front and the back. 
 * 
 * VECTOR vs DEQUE - THE CORE DIFFERENCES:
 * 1. Front Operations: 
 *    - Vector: `push_front` is NOT allowed natively (Doing it manually takes O(N) time).
 *    - Deque: `push_front()` and `pop_front()` are built-in and extremely fast (O(1)).
 * 2. Memory Layout (Under the Hood):
 *    - Vector: Elements are stored in a SINGLE, perfectly contiguous block of memory.
 *    - Deque: Elements are stored in MULTIPLE fixed-size memory blocks (chunks). 
 *      The deque keeps a central "map" or array of pointers to track these blocks.
 * 3. Pointer Arithmetic:
 *    - Vector: `&vec[0] + 1` perfectly points to `vec[1]`.
 *    - Deque: Pointer arithmetic is DANGEROUS! Because memory is broken into chunks, 
 *      `&dq[0] + 1` might point to garbage if `dq[0]` was the last element of its block.
 *      Always use Iterators to traverse a deque!
 * 
 * WHEN TO USE DEQUE?
 * Use a deque when you need to frequently add or remove elements from BOTH the 
 * beginning and the end of the container (e.g., Sliding Window problems, Palindrome checking).
 */

#include <iostream>
#include <deque>

using namespace std;

void demonstrateDequeBasics() {
    cout << "--- 1. Basic Deque Operations (Front & Back) ---\n";
    
    deque<int> dq;
    
    // Pushing to the back (Just like Vector)
    dq.push_back(10);
    dq.push_back(20);
    
    // Pushing to the front (The MAGIC of Deque!)
    dq.push_front(5);
    dq.push_front(1);
    
    cout << "Deque after pushes: ";
    for(int val : dq) {
        cout << val << " "; // Output: 1 5 10 20
    }
    cout << "\n\n";
    
    // Accessing elements (O(1) time complexity)
    cout << "First Element (front) : " << dq.front() << "\n"; // Output: 1
    cout << "Last Element (back)   : " << dq.back() << "\n";  // Output: 20
    cout << "Element at index 2    : " << dq[2] << "\n\n";     // Output: 10
    
    // Popping elements
    dq.pop_front(); // Removes 1 from the front
    dq.pop_back();  // Removes 20 from the back
    
    cout << "Deque after pops: ";
    for(int val : dq) {
        cout << val << " "; // Output: 5 10
    }
    cout << "\n\n";
}

void demonstrateMemoryDifference() {
    cout << "--- 2. The Danger of Pointer Arithmetic in Deque ---\n";
    
    deque<int> dq;
    // Let's add many elements to force the deque to allocate multiple memory chunks
    for (int i = 1; i <= 2000; i++) {
        dq.push_back(i);
    }
    
    cout << "Deque size: " << dq.size() << "\n";
    
    // Safely accessing using operator[]
    cout << "Value at index 1000 using operator[]: " << dq[1000] << " (Safe!)\n\n";
    
    /*
    ❌ CRITICAL WARNING (Pointer Arithmetic):
    In a vector, you can safely do this: 
      int* ptr = &vec[0]; 
      cout << *(ptr + 1000); // This works perfectly because vector is 100% contiguous!
    
    But in a DEQUE, you CANNOT do this safely!
      int* dq_ptr = &dq[0];
      // cout << *(dq_ptr + 1000); // HIGH RISK OF CRASH! (Undefined Behavior)
    
    Why? Because `dq[0]` and `dq[1000]` are almost certainly sitting in two completely 
    different physical memory blocks. The C++ standard does not guarantee that a deque 
    is fully contiguous in memory.
    */
    
    cout << "Professional Rule: Never use raw pointer arithmetic (`&dq[0] + x`) on a deque.\n";
    cout << "Always use Iterators or the `[]` operator instead!\n\n";
}

int main() {
    demonstrateDequeBasics();
    demonstrateMemoryDifference();
    
    /*
    Summary: 
    Deque is a fantastic data structure. It gives you the best of both worlds:
    - O(1) random access (like Arrays/Vectors) via `[]` operator.
    - O(1) insertion/deletion at BOTH ends (like Doubly Linked Lists).
    
    However, it has a slightly higher memory overhead than a vector because of the 
    chunk-management system under the hood. When you only need to push/pop from the back, 
    Vector is still the king!
    */
    
    return 0;
}
