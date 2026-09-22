/**
 * @file practice-stl-deque.cpp
 * @brief Comprehensive Guide to std::deque in C++ STL
 * 
 * WHAT IS A DEQUE?
 * `std::deque` stands for "Double-Ended Queue" (pronounced as "deck").
 * It is a sequence container that allows fast insertion and deletion at BOTH 
 * the front and the back. 
 * 
 * WHY DOES PUSH_FRONT WORK IN DEQUE BUT NOT IN VECTOR? (The Big Question)
 * 
 * 1. The Vector Problem (Single Block Memory):
 *    A vector uses ONE single continuous block of memory. If you have 1,000,000 elements 
 *    in a vector and you want to add a new element at the very front (index 0), you HAVE TO 
 *    shift all 1,000,000 elements one position to the right to make space for the new one.
 *    This shifting takes O(N) time and is extremely slow. 
 *    To prevent developers from accidentally writing very slow code, C++ designers completely 
 *    removed the `push_front()` function from std::vector.
 * 
 * 2. The Deque Solution (Chunked Memory):
 *    A deque does NOT use one single block of memory. Instead, it uses multiple fixed-size 
 *    arrays (called "chunks" or "blocks"), and keeps a central "map" (an array of pointers) 
 *    to track where these chunks are.
 *    
 *    How push_front() works in Deque:
 *    When you call `push_front()`, the deque goes to its FIRST chunk. If there is empty 
 *    space at the front of that chunk, it just puts the data there.
 *    If the first chunk is completely full, the deque simply allocates ONE new empty chunk 
 *    in memory, adds the pointer of this new chunk to the front of its "map", and puts 
 *    the data there. 
 *    Notice the magic? NO EXISTING ELEMENTS WERE SHIFTED! That is why `push_front()` in 
 *    a deque is incredibly fast (O(1) time complexity).
 * 
 * DEEP DIVE: HOW DEQUE WORKS UNDER THE HOOD (The Map & Chunk Architecture)
 * 
 * 1. What exactly is inside a deque object?
 *    When you write `deque<int> dq;`, the deque object itself is quite small. It contains:
 *    - A pointer to a "Map" (An array of pointers).
 *    - The size of this Map.
 *    - A `start` iterator and a `finish` iterator.
 *    (Note: A deque iterator is much heavier than a vector pointer. It contains 4 things: 
 *     a pointer to the current element, a pointer to the start of the chunk, a pointer to 
 *     the end of the chunk, and a pointer back to the Map).
 * 
 * 2. What happens when it is created?
 *    Initially, it allocates a small Map (e.g., an array of 8 pointers) and allocates 
 *    just ONE chunk of memory (often 512 bytes). The `start` and `finish` iterators are 
 *    setup to point to the MIDDLE of this chunk. Why the middle? So that if you do 
 *    `push_front()` or `push_back()`, it has room to grow in both directions immediately!
 * 
 * 3. What happens when you push_back and there is no space?
 *    Unlike a vector (which copies 100% of its data to a 2x larger block), a deque does this:
 *    - It simply allocates ONE new empty chunk of memory (e.g., another 512 bytes).
 *    - It adds the pointer of this new chunk to the next available slot in its "Map".
 *    - It puts your new data into this new chunk.
 *    - NO existing data is copied or shifted!
 * 
 * 4. What if the "Map" itself gets full?
 *    If you add so many chunks that the Map (the array of pointers) gets full, the deque 
 *    will allocate a larger Map, copy the POINTERS to the new Map, and destroy the old Map. 
 *    Copying a few pointers is ridiculously fast compared to copying millions of actual 
 *    data elements (which is what vector does).
 * 
 * 5. Does Deque have a capacity() or reserve() function?
 *    NO! Because a deque never allocates one giant continuous block of memory, the concept 
 *    of "total capacity" doesn't apply to it. It just keeps adding chunks one by one as needed. 
 *    Therefore, `dq.capacity()` or `dq.reserve()` do not exist in C++ STL.
 * 
 * OTHER CORE DIFFERENCES:
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
