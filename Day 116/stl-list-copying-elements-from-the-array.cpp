/*
---------------------------------------------------------------------------
 Copying Elements from a Vector (or List) to a Raw C-Array
---------------------------------------------------------------------------
Raw C-arrays are primitive data types and do NOT have member functions 
like .assign(). However, you can achieve the exact same one-line copying 
magic using the C++ standard algorithm: std::copy().

CRITICAL WARNING: 
Because raw arrays cannot resize dynamically, the destination array MUST 
be pre-declared with a size large enough to hold all the elements coming 
from the vector. Otherwise, your program will crash (Buffer Overflow)!
*/

#include <iostream>
#include <vector>
#include <algorithm> // This header is required for std::copy
using namespace std;

int main() {
    // Source: A vector with 4 elements
    vector<int> vec = {10, 20, 30, 40}; 
    
    // Destination: A raw C-array
    // (Notice: We explicitly gave it a size of 4 to fit the vector)
    int arr[4]; 
    
    /*
    -----------------------------------------------------------------------
     The std::copy Magic
    -----------------------------------------------------------------------
    Syntax: copy(source_start_iterator, source_end_iterator, destination_start)
    
    It takes exactly 3 things:
    1. Where to start copying from (vec.begin())
    2. Where to stop copying from (vec.end())
    3. Where to paste it (arr -> the starting address of the array)
    */
    
    copy(vec.begin(), vec.end(), arr); 
    
    // The array is now populated with: {10, 20, 30, 40}

    return 0;
}