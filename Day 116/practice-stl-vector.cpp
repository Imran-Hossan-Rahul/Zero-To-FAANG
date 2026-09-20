#include <iostream>
#include <vector>
using namespace std;

/*


STL = Standard Template Library
It has four parts. They are Containers, Iterators, Algorithms, Functions

First Container: Vector:
    Ways to create a vector:
        1. vector<int>vec = {1, 2, 3};
        2. vector<int>vec1;
        3. vector<int>vec2(3, 10);
        4. vector<int>vec3(vec2);
    
    Vector Functions:
        Time Complexity => 0(1):
            1. size()
                i. Returns the size of the vector (size = how much elements are currently available).

            2. capacity()
                i. Returns the capacity of the vector (capacity = how much elements it can store).

            3. push_back(ele) => Amortized 0(1)
                i. Add element at the end of the vector.
                ii. Multiple elements can not pushable at once by push_back eg. push_back(2, 3).
                iii. Size will be increase by 1 each time but capacity will be double.

            4. emplace_back() => Amortized 0(1)
                i. Add element at the end of the vector 
                ii. emplace_back(3, 3) won't work because it forwards arguments directly to the element's constructor, and int has no constructor that takes two arguments.
                iii. Every time emplace_used each time size will increase by 1 but if there were enough capacity within the vector to take a new element then the capacity will remain same but if it's not then capacity will be double.

            (
                Both `emplace_back` and `push_back` share an Amortized O(1) time complexity. The core difference is that `push_back` creates an object first and then copies or moves it into the vector, whereas `emplace_back` constructs the object directly in-place using the passed arguments, making it slightly faster. However, if the vector reaches its maximum capacity, both functions must allocate double the memory and copy the existing elements.

                **How the Time Complexity is Calculated:**
                To insert N elements, the vector performs N standard insertions. The periodic memory reallocations (doubling the capacity) require copying previous elements 1 + 2 + 4 + 8 + ... ≈ N - 1 times. Therefore, the total workload for inserting N elements is N + (N - 1) ≈ 2N, which simplifies to a total time of O(N). If we divide this total O(N) cost by the N operations, the average cost per insertion becomes O(N) / N = O(1). This averaged cost over a sequence of operations is what we call Amortized O(1).
            )

            5. pop_back() TC
                i. Remove the last element of the vector.
                ii. Size will decrease by 1 each time.
                iii. Capacity will remain same.

            6. at(idx) and vec[idx]
                i. Both return the value of the index.
                ii. Bounds Checking: vec[i] performs no boundary check, whereas vec.at(i) automatically validates whether the index is within range.
                iii. Invalid Index Behavior: Accessing an out-of-bounds index via vec[i] leads to undefined behavior, while vec.at(i) safely throws an std::out_of_range exception.
                iv. Performance: vec[i] is slightly faster due to zero checking overhead, while vec.at(i) is slightly slower because of the extra boundary verification.
                v. Accessing a garbage element within the vector or an index which is not within the vector, in both case vec.at() will throw out of range exception.
                vi. Out-of-Bounds Behavior with vec[idx]:
                    - Accessing an out-of-bounds index using operator[] leads to Undefined Behavior. It doesn't perform bounds checking; it calculates (base_address + idx * sizeof(type)) and directly accesses that memory.
                    - It often reads a garbage value instead of crashing if the address still lies within the process's allocated OS memory page (typically a 4KB chunk).
                    - However, it can immediately crash the program (Segmentation Fault) due to:
                        1. Negative Index / Unsigned Underflow: A negative index wraps around to a massive positive number (size_t underflow), pointing far outside allocated memory.
                        2. Page Boundary Violation: If the index offset exceeds the current 4KB memory page into restricted or unmapped system memory (common in unbounded loops).
                        3. Invalid Write Operations: Writing to an unauthorized or read-only memory location (e.g., vec[out_of_bounds] = val) causes an instant OS access violation.

            7. front() and back()
                i. Return first and last element of the vector
                ii. Size and capacity of the vector will remain same
            9. empty();
                i. Return if the vector is empty or not

        Time Complexity => 0(N)
            1. insert(pos, val)
                i. Insert element in anywhere of the vector
                ii. If the capacity is not full then element will be added into the vector. It will increase the size by 1 but capacity will remain same as before. But if it's not then capacity will be double from previous and also size will increase by 1 each time.
                iii. multiple elements can be inserted by using vec3.insert(pos, {val,val,val...}). But in a single insert function it is not possible to insert multiple elements in multiple position.
            2. erase(pos) / erase(start-pos, end-pos)
                i. By using erase function single or multiple elements can be remove from the vector.
                ii. After erasing size will decrease depending on how much elements is deleted but capacity will remain same as before.
                ii. Three or more elements can be removed from the vector by providing the range but multiple elments can not be removed by providing individual position within the erase function (erase(pos1,pos2,pos3..) => this won't work)
            3. clear()
                i. Remove all elements from the array
                ii. After using clear() function size will be 0 but the capacity remain same as before.
            4. resize(n)
                i. Resize the vector and make the size n. If it increse the size then new added index's value will be 0 automatically and if it decreases the size of the vector then extra elements will be removed from the vector but in both case capacity remains same. If the size is larger than capacity was, then the capacity will be same as size.
                ii. resize(n, ele) can be used to add n number of ele into the vector. Existing element won't be replaced. They will remain same and if the size increase then new index's value will be replaced with ele.
    
    Vector Iterators:
        1. begin() => Point on 0th index.
        2. end() => Point on nth index.
        3. vector<int>:: iterator it
            Work:
                i. Pointing: It points to or remembers the memory address or location of any element inside a vector<int>.
                ii. Access & Modify: By using dereferencing (*it), it can read the data at a specific position in the vector and can also modify that value if needed (e.g., *it = 50;).
                iii. Traversing: Using it++ or it--, it can move from one element to another within the vector (moving forward or backward).

            Usages:

                i. Looping: It is widely used in for or while loops to print or process all elements from the start to the end of the vector (from begin to end).
                ii. Using STL Algorithms: Iterators are required to work with built-in C++ STL functions such as sort(), find(), reverse(), etc.
                iii. Insert / Erase: To insert a value at a specific index or delete an element from the middle of the vector, an iterator must be passed as an argument (e.g., vec.erase(it);).

            Speciality:

                i. Random Access: The biggest speciality of a vector iterator is its support for "Random Access". This means you can write it + 5 or it - 2 to jump 5 steps forward or 2 steps backward instantly. (Not all iterators support this; for example, map or list iterators cannot jump multiple positions at once).
                ii. Smart & Safe Pointer: It looks and behaves like a raw pointer, but because it is object-oriented, it is much safer than a standard raw pointer and works seamlessly with the C++ Standard Library.
                iii. Abstraction: It allows you to easily interact with the vector's data without needing to know how that data is arranged internally in memory. This abstraction makes the programmer's job much easier.
                iii. In C++, an iterator is not merely a raw memory address but a specific object with its own internal mechanics, which is why a standard iterator and a reverse_iterator are completely distinct data types that cannot be used interchangeably. The core reason lies in how a reverse_iterator operates under the hood: it is designed so that using the ++ operator actually moves it backward in memory, and when dereferenced, it always reads the element located exactly one position before its current stored address. Consequently, if you were to assign it the vector's starting address via begin(), the iterator would attempt to access the memory just before the start of the vector, immediately stepping out of bounds into invalid memory and crashing the program. To avoid both strict type mismatches and fatal memory errors, a reverse_iterator must always be paired with rbegin() and rend(), which correctly establish its starting point at the very end of the vector to ensure safe, backward traversal.


*/


int main (){

    vector<int>vec1;
    cout << "vec1 = {";
    for(int i=0; i<vec1.size(); i++){
        if(i == vec1.size()-1){
            cout << vec1[i];
            break;
        }
        cout << vec1[i] << endl;                                    
    }
    cout << "}" << endl;
    cout << "vec1 capacity: " << vec1.capacity() << endl;           // 0
    cout << "vec1 size: " << vec1.size() << endl;                   // 0
    cout << "vec1 ends here" << endl << endl;
    
    vector<int>vec2(3, 10);
    cout << "vec2 = {";
    for(int i=0; i<vec2.size(); i++){
        if(i == vec2.size()-1){
            cout << vec2[i];
            break;
        }
        cout << vec2[i] << ", ";                                    // print all the elements of vec2;
    }
    cout << "}" << endl;
    cout << "vec2 capacity: " << vec2.capacity() << endl;           // 3
    cout << "vec2 size: " << vec2.size() << endl;                   // 3
    cout << "vec2 ends here" << endl << endl;
    
    
    vector<int>vec3(vec2);
    cout << "vec3 = {";
    for(int i=0; i<vec3.size(); i++){
        if(i == vec3.size()-1){
            cout << vec3[i];
            break;
        }
        cout << vec3[i] << ", ";                                   // print all the elements of vec3 which is similar with vec2;
    }
    cout << "}" << endl;
    cout << "vec3 capacity: " << vec3.capacity() << endl;          // 3
    cout << "vec3 size: " << vec3.size() << endl << endl;                  // 3

    // push_back
    vec3.push_back(2);
    cout << "size after push_back: " << vec3.size() << endl;        // 4
    cout << "capacity after push_back: " << vec3.capacity() << endl << endl;  // 6

    //emplace_back
    vec3.emplace_back(3);
    cout << "size after 1st emplace_back: " << vec3.size() << endl;        // 5
    cout << "capacity after 1st emplace_back: " << vec3.capacity() << endl << endl;  // 6

    vec3.emplace_back(3);
    cout << "size after 2nd emplace_back: " << vec3.size() << endl;        // 6
    cout << "capacity after 2nd emplace_back: " << vec3.capacity() << endl << endl;  // 6

    vec3.emplace_back(3);
    cout << "size after 3rd emplace_back: " << vec3.size() << endl;        // 7
    cout << "capacity after 3rd emplace_back: " << vec3.capacity() << endl << endl;  // 12
    
    // pop_back()
    vec3.pop_back();
    cout << "size after 4th pop_back: " << vec3.size() << endl;        // 6
    cout << "capacity after 4th pop_back: " << vec3.capacity() << endl << endl;  // 12
    
    // at() and []
    cout << "using [] value in index 5 is :" << vec3[5] << endl;
    cout << "using at() value at index 5 is :" << vec3.at(5) << endl;
    cout << "using [] value in a garbage index 12 is :" << vec3[12] << endl;
    // cout << "using at() value in a garbage index 12 is :" << vec3.at(12) << endl;
    cout << "using [] value in a out of bounds index 12 is :" << vec3[15] << endl;
    // cout << "using at() value in a out of bounds index 12 is :" << vec3.at(15) << endl;
    cout << "using [] value in a negative index -1 is :" << vec3[15] << endl;
    // cout << "using at() value in a negative index -1 is :" << vec3.at(15) << endl;
    
    // front()
    cout << "finding the front of the vector using front() function: " << vec3.front() << endl;        // 10
    cout << "size after using front(): " << vec3.size() << endl << endl;        // 6
    
    // back()
    cout << "finding the back of the vector using back() function: " << vec3.back() << endl;        // 3
    cout << "size after using front(): " << vec3.size() << endl << endl;        // 6
    
    // insert()
    cout << "size before using insert(): " << vec3.size() << endl;                                       // 6
    cout << "capacity before using capacity(): " << vec3.capacity() << endl;                             // 12
    cout << "First element before using insert: " << vec3[0] << endl;                                    // 10
    vec3.insert(vec3.begin(), 4);
    cout << "First element after using insert: " << vec3[0] << ". And second is: " << vec3[1] << endl;     // 4, 10
    cout << "size after using insert(): " << vec3.size() << endl;                   // 7
    cout << "capacity after using capacity(): " << vec3.capacity() << endl;       // 7
    //let's make some push_back and make the vector full
    vec3.push_back(4);
    vec3.push_back(4);
    vec3.push_back(2);
    vec3.push_back(9);
    vec3.push_back(5);
    cout << "checking the size and capacity of the vector after push_back: size = " << vec3.size() << ", capacity = " << vec3.capacity() << endl;  // 12, 12
    //now check the size and capacity after insert as the vector is full of its capacity
    vec3.insert(vec3.end() - 1, 1);
    cout << "size after using insert() in the vec3 which is full: " << vec3.size() << endl;                  // 13
    cout << "capacity after using capacity() in the vec3 which is full: " << vec3.capacity() << endl;        // 24
    //inserting multiple elements
    vec3.insert(vec3.end(), {1, 3, 4});
    cout << endl;
    
    //erase()
    cout << "First element before using erase(): " << vec3[0] << endl;                                       // 4
    cout << "size before using erase() in the vec3 which is full: " << vec3.size() << endl;                  // 15
    cout << "capacity before using erase() in the vec3 which is full: " << vec3.capacity() << endl;                  // 24
    vec3.erase(vec3.begin());
    cout << "size after using capacity() in the vec3 which is full: " << vec3.size() << endl;        // 15
    cout << "capacity after using capacity() in the vec3 which is full: " << vec3.capacity() << endl;        // 24
    cout << "First element after using erase(): " << vec3[0] << endl;                                         // 10
    //erasing multiple elements in a single erase function
    vec3.erase(vec3.begin(), vec3.end() - 4);
    cout << endl;
    
    //clear()
    cout << "size before using clear(): " << vec3.size() << endl;                  // 4
    cout << "capacity before using clear(): " << vec3.capacity() << endl;                  // 24
    vec3.clear();
    cout << "size after using clear(): " << vec3.size() << endl;                  // 0
    cout << "capacity after using clear(): " << vec3.capacity() << endl;                  // 24
    
    //resize()
    cout << "size before using resize(): " << vec3.size() << endl;                  // 0
    cout << "capacity before using resize(): " << vec3.capacity() << endl;                  // 24
    vec3.resize(3);
    cout << "size after using resize(): " << vec3.size() << endl;                  // 3
    cout << "capacity after using resize(): " << vec3.capacity() << endl;                  // 24
    //resizing(increasing)
    vec3.resize(5);
    cout << "size after using resize() for the second time: " << vec3.size() << endl;                  // 5
    cout << "capacity after using resize() for the second time: " << vec3.capacity() << endl;                  // 24
    //resizing(increasing)
    vec3.resize(5);
    cout << "size after using resize() for the second time: " << vec3.size() << endl;                  // 5
    cout << "capacity after using resize() for the second time: " << vec3.capacity() << endl;                  // 24
    //resizing(with the value)(increasing)
    vec3.resize(8, 1);
    cout << "size after using resize() for the third time: " << vec3.size() << endl;                  // 8
    cout << "capacity after using resize() for the third time: " << vec3.capacity() << endl;                  // 24
    //resizing(with the value)(decreasing)
    vec3.resize(6, 1);
    cout << "size after using resize() for the third time: " << vec3.size() << endl;                  // 6
    cout << "capacity after using resize() for the third time: " << vec3.capacity() << endl;                  // 24
    
    //resizing (larger than capacity)
    vec3.resize(30, 9);
    cout << "size after using resize() for the third time: " << vec3.size() << endl;                  // 30
    cout << "capacity after using resize() for the third time: " << vec3.capacity() << endl;                  // 30

    //empty()
    cout << "size before using empty(): " << vec3.size() << endl;                  // 30
    cout << "capacity before using empty(): " << vec3.capacity() << endl;                  // 30
    vec3.empty();
    cout << "size after using empty(): " << vec3.size() << endl;                  // 30
    cout << "capacity after using empty(): " << vec3.capacity() << endl;                  // 30
    cout << vec3.empty() << endl;                                                  // 0
    //after clear
    // vec3.clear();                                                                   
    cout << vec3.empty() << endl;                                                 // 1

    //Vector Iterators
    cout << "vec3 = {";
    for(int i=0; i<vec3.size(); i++){
        if(i == vec3.size()-1){
            cout << vec3[i];
            break;
        }
        cout << vec3[i] << ", ";                                    
    }
    cout << "}" << endl;
    cout << "first element: " << *vec3.begin() << endl;
    cout << "last element: " << *(vec3.end() - 1) << endl;
    cout << "what is before the first element: " << *(vec3.begin() - 1)<< endl;
    cout << "nth thing or element is: " << *vec3.end()<< endl;
    cout << "vec3 ends here" << endl << endl;

    //vector<int>::iterator it
    vector<int>::iterator it;                                   // now it just has garbage value
    cout << "printing elements of vec3 using it operator: ";
    for(it = vec3.begin(); it < vec3.end(); it++){
        if(it == vec3.end()-1){
            cout << *it << endl;
            break;
        }
        cout << *it << ", ";
    }
    //vector<int>:: reverse_iterator rit;
    vector<int>:: reverse_iterator rit;
    cout << "printing elements in descending order of vec3 using rit operator: ";
    for(rit = vec3.rbegin(); rit != vec3.rend(); rit++){
        if(rit == vec3.rend()-1){
            cout << *rit << endl;
            break;
        }
        cout << *rit << ", ";
    }
    cout << "printing elements in descending order of vec3 using it operator: ";
    for(it = vec3.end()-1; it != vec3.begin(); it--){
        if(it == vec3.begin()-1){
            cout << *it << endl;
            break;
        }
        cout << *it << ", ";
    }
    //another way to do the same
    cout << "printing elements in ascending order of vec3 using it operator but in a smarter way: ";
    for(auto it2 = vec3.begin(); it2 != vec3.end(); it2++){
        if(it2 == vec3.end()-1){
            cout << *it2 << endl;
            break;
        }
        cout << *it2 << ", ";
    }
    return 0;
    
}