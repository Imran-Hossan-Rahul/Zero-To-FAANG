#include <iostream>
#include <list>
using namespace std;








/* 
===========================================================================
        VECTOR VS LIST: MISSING FUNCTIONS & MEMORY BEHAVIOR IN C++
===========================================================================
*/

/*
---------------------------------------------------------------------------
 1. Functions present in `std::vector` but MISSING in `std::list`
---------------------------------------------------------------------------
Since `list` is a Doubly Linked List (node-based) and not contiguous, 
it lacks functions related to Random Access and Capacity management.

* operator[] and at() : 
  You cannot access elements by index in a list (e.g., list[3] is invalid). 
  To reach the 4th element, a list must traverse from the beginning one by one.

* capacity() : 
  A list does not pre-allocate extra memory. (Detailed explanation below).

* reserve(n) : 
  Since there is no capacity concept, you cannot ask a list to reserve 
  memory in advance.

* shrink_to_fit() : 
  A list never holds unused memory, so there is nothing to shrink.

* data() : 
  Returns a raw pointer to the underlying array. Since a list's elements 
  are scattered in memory, it has no underlying raw C-style array.
*/


/*
---------------------------------------------------------------------------
 2. Functions present in `std::list` but MISSING in `std::vector`
---------------------------------------------------------------------------
Since `vector` relies on contiguous memory, node-manipulation and front-insertion 
functions are excluded to prevent O(N) performance drops.

* push_front(), emplace_front(), pop_front() : 
  These are O(1) in a list (just updating pointers). They are excluded from 
  vectors because shifting all contiguous elements backward/forward takes O(N) time.

* splice() : 
  Transfers elements from one list to another instantly by just changing 
  node pointers, without copying or moving the actual data.

* remove(value) / remove_if(condition) : 
  List has built-in functions to safely delete specific values anywhere in 
  the sequence by simply unlinking the nodes.

* unique() : 
  Instantly removes consecutive duplicate elements by updating node pointers.

* merge() : 
  Merges two sorted lists into one perfectly sorted list without copying data, 
  only rewiring the pointers.

* sort() : 
  List has its own built-in `.sort()` member function. You cannot use the 
  standard `std::sort(list.begin(), list.end())` because `std::sort` requires 
  Random Access Iterators, which `list` does not have.
*/


/*
---------------------------------------------------------------------------
 3. Why `std::list` Does NOT Have a capacity() Function (Memory Behavior)
---------------------------------------------------------------------------
The absence of capacity() in std::list fundamentally comes down to how it 
allocates memory compared to a vector.

* The Vector (The Bus Analogy): 
  A vector requires "Contiguous Memory" (elements sitting side-by-side). 
  Because of this, it must pre-allocate extra empty spaces in advance so 
  new elements can be added quickly without shifting to a new memory block 
  every single time. This total pre-allocated space is called its "capacity".

* The List (The Train Analogy):
  A list is a "Doubly Linked List". Its elements (Nodes) are scattered 
  randomly throughout the RAM, connected to each other via pointers 
  (like chain links connecting train carriages). 

* Dynamic On-Demand Allocation:
  A list does not pre-allocate any empty memory. When you add a new element, 
  it dynamically creates exactly one new Node in the RAM at that exact moment 
  and links it to the chain. When you delete an element, that Node is instantly 
  destroyed and the memory is freed.

* Size == Capacity:
  Because a list only ever occupies the exact amount of memory needed for 
  its current elements, it has no "extra unused space". Therefore, for a list, 
  its Size is ALWAYS equal to its theoretical Capacity. Since there is never 
  any extra reserved space to keep track of, the capacity() function does not 
  exist in std::list.
===========================================================================
*/                       









int main(){

    
    int arr[] = {50, 60, 70, 80};
    int size = sizeof(arr) / sizeof(arr[0]);

    list<int>l;
    l.assign(arr, arr + size);                      //copping array elements into the list (same for vector to list and list to vector)

    return 0;
}