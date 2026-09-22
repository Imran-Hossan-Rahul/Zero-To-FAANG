/**
 * @file set.cpp
 * @brief Comprehensive Guide to Sets in C++ STL (set, unordered_set, multiset)
 * 
 * WHAT IS A SET?
 * A Set is a container that stores elements automatically following a specific rule.
 * The primary rule of a standard Set is that all elements must be UNIQUE. 
 * (Think of it like a mathematical set).
 * 
 * 1. std::set (Ordered Set)
 *    - Under the hood: Uses a Red-Black Tree (Self-balancing Binary Search Tree).
 *    - Sorting: Elements are ALWAYS sorted automatically (ascending order by default).
 *    - Duplicates: NOT allowed. If you try to insert a duplicate, it is silently ignored.
 *    - Time Complexity: O(log N) for insertion, deletion, and searching.
 * 
 * 2. std::unordered_set
 *    - Under the hood: Uses a Hash Table.
 *    - Sorting: Elements are NOT sorted. They appear in completely random order.
 *    - Duplicates: NOT allowed.
 *    - Time Complexity: O(1) average case for insertion, deletion, and searching! 
 *      (Worst case is O(N) if many hash collisions occur).
 *    - Best for: When you need extremely fast lookups and don't care about order.
 * 
 * 3. std::multiset
 *    - Under the hood: Same as `std::set` (Red-Black Tree).
 *    - Sorting: Elements are sorted automatically.
 *    - Difference: Allows DUPLICATE elements! (You can store multiple 10s).
 *    - Time Complexity: O(log N).
 * 
 * IMPORTANT FUNCTIONS:
 * - insert(val)  : Inserts a value.
 * - erase(val)   : Deletes the value. (WARNING: In multiset, it deletes ALL instances of that value!).
 * - find(val)    : Returns an iterator to the value, or `end()` if not found.
 * - count(val)   : Returns 1 if exists, 0 if not (returns >1 in multiset).
 * - lower_bound(), upper_bound() : Extremely useful functions for finding boundaries in sorted sets.
 */

#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

void demonstrateSet() {
    cout << "--- 1. std::set (Ordered & Unique) ---\n";
    set<int> s;
    
    // Insertion
    s.insert(50);
    s.insert(10);
    s.insert(30);
    s.insert(30); // Duplicate! Will be SILENTLY ignored by the set.
    
    // Iteration (Notice it prints in SORTED order: 10, 30, 50)
    cout << "Set elements (Sorted): ";
    for (int val : s) {
        cout << val << " ";
    }
    cout << "\n\n";
}

void demonstrateUnorderedSet() {
    cout << "--- 2. std::unordered_set (Unordered & Unique, O(1) Time) ---\n";
    unordered_set<int> uset;
    
    uset.insert(50);
    uset.insert(10);
    uset.insert(30);
    
    cout << "Unordered Set elements (Random Order): ";
    for (int val : uset) {
        cout << val << " "; // Output order is completely unpredictable!
    }
    cout << "\n\n";
}

void demonstrateMultiset() {
    cout << "--- 3. std::multiset (Ordered & DUPLICATES allowed) ---\n";
    multiset<int> mset;
    
    mset.insert(10);
    mset.insert(10); // Duplicate allowed!
    mset.insert(10); // Duplicate allowed!
    mset.insert(5);
    
    cout << "Multiset elements (Notice duplicates): ";
    for (int val : mset) {
        cout << val << " "; // Output: 5 10 10 10
    }
    cout << "\n";
    
    cout << "Count of 10: " << mset.count(10) << " times.\n";
    
    /* 
    ❌ DANGER OF ERASE IN MULTISET:
    If you do `mset.erase(10)`, it will delete ALL instances of 10 in the multiset!
    If you only want to delete ONE instance of 10, you must find its iterator first:
    mset.erase(mset.find(10));
    */
    mset.erase(mset.find(10)); // Safely deletes only one '10'
    cout << "After erasing one 10 safely, Count of 10: " << mset.count(10) << " times.\n\n";
}

void interviewProTip() {
    cout << "--- 4. INTERVIEW PRO TIP: You Cannot Modify Set Elements! ---\n";
    
    set<int> s = {1, 2, 3};
    
    auto it = s.find(2);
    if (it != s.end()) {
        // *it = 99; // ❌ COMPILER ERROR! Elements in a set are always CONST. 
        
        /*
        Why? Because a Set uses a Red-Black Tree under the hood to keep elements sorted.
        If you manually change a value (e.g., changing 2 to 99), it destroys the 
        internal sorting structure of the tree!
        
        Correct way to "modify" a value in a Set:
        */
        s.erase(it);   // 1. Delete the old value
        s.insert(99);  // 2. Insert the new value (the tree will auto-sort it properly)
    }
    
    cout << "Modified set elements: ";
    for (int val : s) {
        cout << val << " "; // Output: 1 3 99
    }
    cout << "\n";
}

int main() {
    demonstrateSet();
    demonstrateUnorderedSet();
    demonstrateMultiset();
    interviewProTip();
    
    /*
    Summary of when to use what:
    - Need sorted unique items? -> std::set (O(log N))
    - Need extremely fast lookups for unique items? -> std::unordered_set (O(1))
    - Need sorted items with duplicates allowed? -> std::multiset (O(log N))
    */
    
    return 0;
}
