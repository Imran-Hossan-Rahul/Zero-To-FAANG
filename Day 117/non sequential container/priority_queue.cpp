/**
 * @file priority_queue.cpp
 * @brief Comprehensive Guide to std::priority_queue in C++ STL
 * 
 * WHAT IS A PRIORITY QUEUE?
 * A Priority Queue is a "Container Adapter" that acts like a normal queue, 
 * but instead of FIFO (First-In, First-Out), the elements are popped based on 
 * their PRIORITY. 
 * Under the hood, it uses a Heap data structure (usually implemented over a Vector).
 * 
 * MAX-HEAP vs MIN-HEAP (The sorting behavior):
 * 1. Max-Heap (Default behavior): 
 *    The element with the HIGHEST value is given the highest priority. 
 *    So, the largest element will ALWAYS be at the top().
 * 2. Min-Heap: 
 *    The element with the LOWEST value is given the highest priority.
 *    So, the smallest element will ALWAYS be at the top().
 * 
 * TIME COMPLEXITIES OF MEMBER FUNCTIONS:
 * - push(val) : O(log N) -> It has to re-balance the heap tree after inserting.
 * - pop()     : O(log N) -> It has to re-balance the heap tree after removing the top.
 * - top()     : O(1)     -> Just returns the root of the heap tree.
 * - size()    : O(1)
 * - empty()   : O(1)
 * 
 * INTERVIEW PRO TIP (Heapify / Range Initialization):
 * If you push N elements one by one using a loop, the total time is O(N log N).
 * But if you initialize a priority queue directly from a vector (Range Constructor), 
 * C++ builds the heap using an algorithm called "Heapify", which takes exactly O(N) time!
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void demonstrateMaxHeap() {
    cout << "--- 1. MAX-HEAP (Default Priority Queue) ---\n";
    
    // By default, C++ creates a Max-Heap
    priority_queue<int> maxHeap;
    
    maxHeap.push(10);
    maxHeap.push(50);
    maxHeap.push(20);
    maxHeap.push(40);
    
    cout << "Max-Heap Top Element: " << maxHeap.top() << " (Highest value is at the top)\n";
    
    cout << "Popping elements from Max-Heap (Decreasing Order): ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " "; // Output: 50 40 20 10
        maxHeap.pop(); // O(log N) operation
    }
    cout << "\n\n";
}

void demonstrateMinHeap() {
    cout << "--- 2. MIN-HEAP (Reversed Priority) ---\n";
    
    /* 
    To create a Min-Heap, we have to pass 3 template arguments:
    1. Data Type (int)
    2. Underlying Container (vector<int>)
    3. Comparator (greater<int> -> This tells it to put the smallest element at the top)
    */
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    minHeap.push(10);
    minHeap.push(50);
    minHeap.push(20);
    minHeap.push(40);
    
    cout << "Min-Heap Top Element: " << minHeap.top() << " (Lowest value is at the top)\n";
    
    cout << "Popping elements from Min-Heap (Increasing Order): ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " "; // Output: 10 20 40 50
        minHeap.pop(); // O(log N) operation
    }
    cout << "\n\n";
}

void demonstrateO_N_Initialization() {
    cout << "--- 3. O(N) Initialization (Heapify Trick) ---\n";
    
    vector<int> myVec = {15, 5, 25, 35, 2};
    
    // BAD WAY: Pushing one by one using a loop takes O(N log N) time.
    // GOOD WAY: Range Constructor! It builds the heap from a vector in O(N) time.
    priority_queue<int> pq(myVec.begin(), myVec.end());
    
    cout << "Top element built from vector in O(N) time: " << pq.top() << "\n\n"; 
    // Output: 35
}

int main() {
    demonstrateMaxHeap();
    demonstrateMinHeap();
    demonstrateO_N_Initialization();
    
    /*
    Summary: 
    Priority Queue is extremely powerful for problems where you constantly need to 
    find the MAXIMUM or MINIMUM element among a dynamically changing set of numbers 
    (e.g., Dijkstra's Algorithm, K-th largest/smallest element problems).
    */
    
    return 0;
}
