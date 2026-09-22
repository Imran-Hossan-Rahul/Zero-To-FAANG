/**
 * @file vector-qna.cpp
 * @brief Q&A: Memory allocation of std::vector and the behavior of the end() iterator.
 * 
 * =========================================================================================
 * QUESTION:
 * If a vector is created and its capacity is set to 5 (e.g., using reserve(5)), it allocates 
 * 5 blocks of memory on the heap. 
 * We know the `end()` iterator points to the memory location "one step after the last element". 
 * Does the vector allocate a 6th block of memory just for `end()` to point to? 
 * If not, where exactly does `end()` point?
 * =========================================================================================
 * 
 * ANSWER:
 * No, the vector does NOT allocate any extra memory blocks for the `end()` iterator. 
 * If the capacity is 5, exactly 5 blocks of memory (e.g., 5 * 4 = 20 bytes for integers) 
 * are allocated on the heap. Not a single byte more.
 * 
 * HOW IT WORKS (UNDER THE HOOD):
 * 1. The "One Past the End" Rule in C++: 
 *    The C++ standard guarantees that you are allowed to calculate and store a pointer to the 
 *    memory address immediately following an array, even though you do not own that memory.
 * 
 * 2. Pointer Arithmetic: 
 *    Because arrays are contiguous in memory, `end()` is simply calculated mathematically: 
 *    `Address of end() = Start_Address + (Size * Size_Of_Data_Type)`.
 * 
 * 3. Where does end() point? 
 *    It points to whatever memory happens to be physically adjacent to your vector on the heap. 
 *    That adjacent memory might belong to another program, another variable, or it might be 
 *    unmapped garbage data. 
 * 
 * 4. Why doesn't it crash? 
 *    It doesn't crash because `end()` is just STORING a memory address (a number). 
 *    The operating system only crashes your program if you try to DEREFERENCE it (i.e., read 
 *    or write to it using `*end()`), because you don't have permission to access that neighbor's 
 *    memory. But simply pointing at it (storing the address as a boundary marker) is 100% legal.
 * 
 * =========================================================================================
 * QUESTION 2: 
 * Since the vector object itself is created in memory (e.g., on the stack), what exactly 
 * does it store? What pointers does it keep track of by default to manage its data?
 * =========================================================================================
 * 
 * ANSWER:
 * A standard `std::vector` object typically stores exactly THREE pointers (or their equivalents 
 * depending on the compiler implementation) to manage the dynamic array on the heap.
 * 
 * 1. Pointer to the BEGINNING of allocated memory (internally often called `_M_start`).
 *    This points to the very first block of your allocated heap memory.
 * 
 * 2. Pointer to the CURRENT END of elements (internally often called `_M_finish`).
 *    This points to the memory location exactly one step after the last inserted element. 
 *    - `end()` simply returns this pointer.
 *    - `size()` is calculated using Pointer Arithmetic: `_M_finish - _M_start`. 
 *      (Example: If start is at address 1000, finish is at 1020, and each int is 4 bytes: 
 *       Distance is 20 bytes. 20 / 4 = 5 elements. So, size() returns 5).
 * 
 * 3. Pointer to the END OF STORAGE / CAPACITY (internally often called `_M_end_of_storage`).
 *    This points to the very end of the total reserved memory block.
 *    - `capacity()` is calculated the same way: `_M_end_of_storage - _M_start`.
 *      (Example: If you reserved 10 blocks, this pointer sits at address 1040. 
 *       Distance is 40 bytes. 40 / 4 = 10 blocks. So, capacity() returns 10).
 * 
 * Q3: What happens if Size and Capacity are different? 
 * A: If you reserve 10 blocks but only add 5 elements, `_M_finish` will point to the 6th block, 
 *    while `_M_end_of_storage` will point to the 11th block. They are totally independent!
 * 
 * =========================================================================================
 * QUESTION 4: 
 * For an array, the address of the array itself is the same as its first element. 
 * Then what is the address of the vector variable `vec` itself (`&vec`)?
 * =========================================================================================
 * 
 * ANSWER:
 * The vector object `vec` and its actual elements live in TWO DIFFERENT PLACES in memory!
 * 
 * 1. The `vec` Object (Stack): When you write `vector<int> vec;`, the object `vec` is created 
 *    on the Stack. So `&vec` gives you a Stack memory address. This object just holds the 
 *    3 internal pointers we discussed above.
 * 
 * 2. The Elements (Heap): The actual data (like `10, 20, 30`) is dynamically allocated on the Heap.
 *    The address of the first element (`&vec[0]` or `vec.data()`) is a Heap memory address.
 * 
 * Because of this, `&vec` (address of the vector object) and `&vec[0]` (address of the first 
 * element) are completely different addresses!
 * 
 * Summary: The vector object itself is very lightweight (typically 24 bytes on a 64-bit system: 
 * 3 pointers x 8 bytes each). All the heavy elements are stored separately on the heap!
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "==========================================\n";
    cout << "   Vector Memory & end() Iterator Demo    \n";
    cout << "==========================================\n\n";

    // 1. Create an empty vector
    vector<int> vec;
    
    // 2. Reserve a capacity of 5 (Allocates exactly 5 memory blocks)
    vec.reserve(5);
    
    // Add 5 elements so Size == Capacity
    vec = {10, 20, 30, 40, 50};
    
    cout << "Vector Size: " << vec.size() << "\n";
    cout << "Vector Capacity: " << vec.capacity() << "\n\n";
    
    // Demonstrate the difference between &vec and &vec[0]
    cout << "--- Address of Object vs Address of Elements ---\n";
    cout << "Address of the vector object `vec` (&vec) : " << &vec << " (Lives on the Stack)\n";
    cout << "Address of the first element (&vec[0])    : " << &vec[0] << " (Lives on the Heap)\n\n";
    
    // 3. Let's look at the memory addresses of the 5 allocated blocks
    const int* start_ptr = vec.data(); // Points to the first element
    
    for (int i = 0; i < 5; i++) {
        cout << "Address of element " << i << " (Value: " << vec[i] << ") : " << (start_ptr + i) << "\n";
    }
    
    // 4. Where is end() pointing?
    // It is mathematically exactly 1 block (4 bytes) after the last element.
    const int* calculated_end_ptr = start_ptr + vec.size();
    
    cout << "------------------------------------------\n";
    cout << "Address of end() iterator      : " << calculated_end_ptr << "\n";
    cout << "------------------------------------------\n";
    
    cout << "\nNotice how the address of end() continues perfectly after element 4.\n";
    cout << "The vector didn't allocate this space; it just uses this address as a mathematical boundary!\n";

    return 0;
}
