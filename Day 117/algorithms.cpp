/**
 * @file algorithms.cpp
 * @brief Comprehensive Guide to C++ STL Algorithms
 * 
 * WHAT ARE STL ALGORITHMS?
 * STL provides a collection of functions specially designed to be used on ranges of elements.
 * A "range" is usually defined by two iterators: `begin()` and `end()`.
 * These built-in algorithms save time, reduce bugs, and are highly optimized!
 * 
 * REQUIRED HEADERS:
 * - `#include <algorithm>` : For sorting, searching, reversing, min/max, etc.
 * - `#include <numeric>`   : For math operations like `accumulate()` (Sum).
 * 
 * MOST FREQUENTLY USED ALGORITHMS IN INTERVIEWS & CP:
 * 
 * 1. Sorting & Reversing:
 *    - sort()    : O(N log N). Sorts ascending by default. (Uses IntroSort = QuickSort + HeapSort + InsertionSort).
 *    - reverse() : O(N). Reverses the order of elements.
 * 
 * 2. Min/Max & Math:
 *    - min_element() : O(N). Returns an ITERATOR to the minimum element.
 *    - max_element() : O(N). Returns an ITERATOR to the maximum element.
 *    - accumulate()  : O(N). Returns the sum of all elements.
 * 
 * 3. Searching & Counting:
 *    - count()         : O(N). Counts occurrences of a specific value.
 *    - find()          : O(N). Returns an iterator to the first occurrence of a value.
 *    - binary_search() : O(log N). Returns true/false if element exists (Array MUST be sorted!).
 * 
 * 4. Bound Functions (Crucial for FAANG Interviews):
 *    - lower_bound() : O(log N). Returns iterator to the first element that is >= value.
 *    - upper_bound() : O(log N). Returns iterator to the first element that is > value.
 *    (Array MUST be sorted for bounds to work!).
 * 
 * 5. Permutations:
 *    - next_permutation() : Rearranges elements into the next lexicographically greater arrangement.
 */

#include <iostream>
#include <vector>
#include <algorithm> // Core STL Algorithms
#include <numeric>   // For accumulate
#include <string>

using namespace std;

void demonstrateSortingAndReversing() {
    cout << "--- 1. Sorting and Reversing ---\n";
    vector<int> vec = {40, 10, 50, 20, 30};
    
    // Default Sort (Ascending)
    sort(vec.begin(), vec.end());
    cout << "Ascending Sort: ";
    for (int v : vec) cout << v << " "; // Output: 10 20 30 40 50
    cout << "\n";
    
    // Descending Sort (Using greater<int>())
    sort(vec.begin(), vec.end(), greater<int>());
    cout << "Descending Sort: ";
    for (int v : vec) cout << v << " "; // Output: 50 40 30 20 10
    cout << "\n";
    
    // Reverse (Reverses whatever the current order is)
    reverse(vec.begin(), vec.end());
    cout << "Reversed Array: ";
    for (int v : vec) cout << v << " "; // Output: 10 20 30 40 50
    cout << "\n\n";
}

void demonstrateMathAndMinMax() {
    cout << "--- 2. Math, Min, and Max ---\n";
    vector<int> vec = {5, 2, 9, 1, 7};
    
    // min_element and max_element return ITERATORS, so we must dereference (*) them to get the value!
    int minVal = *min_element(vec.begin(), vec.end());
    int maxVal = *max_element(vec.begin(), vec.end());
    
    cout << "Min Value: " << minVal << "\n";
    cout << "Max Value: " << maxVal << "\n";
    
    // accumulate(start, end, initial_sum_value)
    int sum = accumulate(vec.begin(), vec.end(), 0);
    cout << "Sum of elements: " << sum << "\n\n";
}

void demonstrateSearchingAndCounting() {
    cout << "--- 3. Searching and Counting (Unsorted Arrays) ---\n";
    vector<int> vec = {10, 20, 30, 20, 40, 20, 50};
    
    // Count occurrences of 20
    int totalTwenties = count(vec.begin(), vec.end(), 20);
    cout << "20 appears " << totalTwenties << " times.\n";
    
    // Find an element (returns iterator)
    auto it = find(vec.begin(), vec.end(), 30);
    if (it != vec.end()) {
        // We use distance() to find the index of the iterator
        cout << "30 is found at index: " << distance(vec.begin(), it) << "\n";
    } else {
        cout << "30 is NOT found!\n";
    }
    cout << "\n";
}

void demonstrateBinarySearchAndBounds() {
    cout << "--- 4. Binary Search & Bounds (CRITICAL FOR INTERVIEWS) ---\n";
    
    // ❌ WARNING: The array MUST be sorted for these O(log N) functions to work!
    vector<int> vec = {10, 20, 30, 30, 30, 40, 50};
    
    // 1. Binary Search (Returns true/false only)
    bool exists = binary_search(vec.begin(), vec.end(), 30);
    cout << "Does 30 exist? " << (exists ? "Yes" : "No") << "\n";
    
    // 2. lower_bound (Finds first element >= val)
    auto lb = lower_bound(vec.begin(), vec.end(), 30);
    cout << "Lower Bound of 30 (First >= 30) is at index: " << distance(vec.begin(), lb) << "\n";
    
    // 3. upper_bound (Finds first element > val)
    auto ub = upper_bound(vec.begin(), vec.end(), 30);
    cout << "Upper Bound of 30 (First > 30) is at index: " << distance(vec.begin(), ub) << "\n";
    
    // Pro Tip: Find exactly how many times an element appears in O(log N) time!
    cout << "30 appears " << distance(lb, ub) << " times (calculated using bounds!).\n\n";
}

void demonstrateNextPermutation() {
    cout << "--- 5. Next Permutation ---\n";
    string s = "abc"; // Should be sorted if you want ALL permutations
    
    cout << "All permutations of 'abc':\n";
    do {
        cout << "  " << s << "\n";
    } while (next_permutation(s.begin(), s.end()));
    
    /*
    How it works:
    It changes the string to the very next dictionary-order arrangement.
    When it reaches the absolute last arrangement ("cba"), it returns false, stopping the loop.
    */
    cout << "\n";
}

int main() {
    demonstrateSortingAndReversing();
    demonstrateMathAndMinMax();
    demonstrateSearchingAndCounting();
    demonstrateBinarySearchAndBounds();
    demonstrateNextPermutation();
    
    /*
    Professional Tip:
    Never write your own sort, reverse, or binary search functions in an interview 
    unless the interviewer explicitly asks you to build it from scratch! 
    Using STL algorithms shows that you know modern C++ and can write bug-free, 
    highly optimized code quickly.
    */
    
    return 0;
}
