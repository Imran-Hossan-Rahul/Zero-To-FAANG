#include <iostream>
#include <vector>
#include <list>
using namespace std;



/*
===========================================================================
        DEEP DIVE: WHAT IS assign() AND HOW DOES IT ACTUALLY WORK?
===========================================================================
*/

/*
---------------------------------------------------------------------------
 1. WHAT DOES assign() DO? (The Concept)
---------------------------------------------------------------------------
The `assign()` function is a container member function in C++ STL (like 
vector and list). Its primary job is to completely REPLACE the current 
contents of a container with new data. 

When you call `assign()`, it does three things simultaneously:
  1. Wipes out all the old elements.
  2. Automatically adjusts the "Size" of the container to match the new data.
  3. Fills the container with the brand new elements.
*/


/*
---------------------------------------------------------------------------
 2. HOW DOES IT WORK UNDER THE HOOD? (The Internal Mechanics)
---------------------------------------------------------------------------
You might wonder: "Why use assign() instead of just clearing the vector 
and pushing new elements?" The answer lies in how `assign()` smartly manages 
memory under the hood.

Here is the step-by-step internal process of how `assign()` works:

A. For std::vector (Contiguous Memory):
   When you call `vec.assign(new_size, value)`, the vector checks its 
   current CAPACITY (not size, but the actual reserved memory).
   
   * Scenario 1: New Size <= Current Capacity (Highly Efficient!)
     If the vector already has enough reserved memory, it DOES NOT destroy 
     the old memory block. It simply overwrites the old values with the 
     new ones and updates the `size` counter. This prevents expensive 
     memory reallocation and makes the program run incredibly fast.
     
   * Scenario 2: New Size > Current Capacity (Reallocation Required)
     If the new data is larger than the currently reserved space, the 
     vector is forced to request a brand new, larger block of contiguous 
     memory from the RAM. It constructs the new elements there, deletes 
     the old memory block, and points to the new one.

B. For std::list (Node-Based Memory):
   Since a list does not have "capacity" and creates nodes on demand, 
   `assign()` acts a bit differently to save time. 
   Instead of deleting all old nodes and creating entirely new ones, 
   `assign()` will REUSE existing nodes by simply overwriting their values. 
   - If the new data is larger, it reuses all old nodes and creates new 
     nodes for the extra data.
   - If the new data is smaller, it reuses the necessary nodes and deletes 
     the remaining excess nodes.
*/


/*
---------------------------------------------------------------------------
 3. assign() vs ( clear() + push_back() )
---------------------------------------------------------------------------
Why is `assign()` the professional choice?

* BAD APPROACH (The Amateur Way):
  vec.clear();             // Destroys all elements and sets size to 0.
  for(int i=0; i<5; i++) { 
      vec.push_back(10);   // Keeps adding elements one by one.
  }
  -> Problem: push_back() has to constantly check if the vector needs 
     to grow. This continuous checking slows down the CPU.

* GOOD APPROACH (The Professional Way):
  vec.assign(5, 10);
  -> Benefit: `assign()` knows exactly how many elements are coming (5). 
     It checks the capacity exactly ONCE, allocates memory ONCE (if needed), 
     and writes the data instantly. It is highly optimized!
*/


/*
using assign() for vector
int main(){

    int arr[5];
    vector<int>vec, vec2;
    list<int>l;

    vec.assign({1, 2, 3}); // Assigning multiple elements at once
    vec.assign(5, -1);     // Assigning a single element for multiple time   v.assign(count, value);
    vec2.assign(vec.begin(), vec.end());          // Assigning a part of vec2    v.assign(first, last);
    vec2.assign(l.begin(), l.end());
    vec.assign(arr, arr+5);
    return 0;


}

Another to list
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {

    int arr[5] = {10, 20, 30, 40, 50};
    vector<int> vec = {1, 2, 3, 4, 5};
    list<int> l;
    l.assign(vec.begin(), vec.end());
    l.assign(vec.begin() + 1, vec.begin() + 4);
    l.assign(arr, arr + 5);
    l.assign(arr + 1, arr + 4);

    // list to list
    list<int> l1 = {1, 2, 3, 4, 5};
    list<int> l2;
    l2.assign(l1.begin(), l1.end());
    l2.assign(next(l1.begin()), next(l1.begin(), 4));

    return 0;
}




// Another to array
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {

    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2;

    list<int> l1 = {10, 20, 30, 40, 50};
    list<int> l2;

    int arr1[5] = {100, 200, 300, 400, 500};
    int arr2[5];


    // Copying all elements from vector to vector
    vec2.assign(vec1.begin(), vec1.end());


    // Copying selected elements from vector to vector
    vec2.assign(vec1.begin() + 1, vec1.begin() + 4);


    // Copying all elements from list to vector
    vec2.assign(l1.begin(), l1.end());


    // Copying selected elements from list to vector
    vec2.assign(next(l1.begin()), next(l1.begin(), 4));


    // Copying all elements from array to vector
    vec2.assign(arr1, arr1 + 5);


    // Copying selected elements from array to vector
    vec2.assign(arr1 + 1, arr1 + 4);


    // Copying all elements from vector to list
    l2.assign(vec1.begin(), vec1.end());


    // Copying selected elements from vector to list
    l2.assign(vec1.begin() + 1, vec1.begin() + 4);


    // Copying all elements from list to list
    l2.assign(l1.begin(), l1.end());


    // Copying selected elements from list to list
    l2.assign(next(l1.begin()), next(l1.begin(), 4));


    // Copying all elements from array to list
    l2.assign(arr1, arr1 + 5);


    // Copying selected elements from array to list
    l2.assign(arr1 + 1, arr1 + 4);


    // Copying all elements from vector to array
    copy(vec1.begin(), vec1.end(), arr2);


    // Copying selected elements from vector to array
    copy(vec1.begin() + 1, vec1.begin() + 4, arr2);


    // Copying all elements from list to array
    copy(l1.begin(), l1.end(), arr2);


    // Copying selected elements from list to array
    copy(next(l1.begin()), next(l1.begin(), 4), arr2);


    return 0;
}

*/