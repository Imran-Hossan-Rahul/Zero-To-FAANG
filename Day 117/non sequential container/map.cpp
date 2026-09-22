/**
 * @file map.cpp
 * @brief Comprehensive Guide to Maps in C++ STL (map, unordered_map, multimap)
 * 
 * WHAT IS A MAP?
 * A Map is a container that stores elements as Key-Value pairs. 
 * - Keys must be UNIQUE (except in multimap).
 * - A key is used to look up its corresponding value quickly.
 * 
 * 1. std::map (Ordered Map)
 *    - Under the hood: Uses a Red-Black Tree (Self-balancing Binary Search Tree).
 *    - Sorting: Keys are ALWAYS sorted automatically (ascending order by default).
 *    - Time Complexity: O(log N) for insertion, deletion, and searching.
 * 
 * 2. std::unordered_map
 *    - Under the hood: Uses a Hash Table.
 *    - Sorting: Keys are NOT sorted. They appear in random order based on their hash.
 *    - Time Complexity: O(1) average case for insertion, deletion, and searching! 
 *      (Worst case is O(N) if many hash collisions occur).
 *    - Best for: When you just need fast lookups and don't care about order.
 * 
 * 3. std::multimap
 *    - Under the hood: Same as `std::map` (Red-Black Tree).
 *    - Sorting: Keys are sorted.
 *    - Difference: Allows DUPLICATE keys! (You can have two "Alice" keys).
 *    - Note: The `[]` operator is NOT allowed in multimap because the compiler 
 *      wouldn't know which duplicate key's value you want to access.
 * 
 * IMPORTANT FUNCTIONS:
 * - insert({key, val}) : Inserts a key-value pair.
 * - operator[]         : `map[key] = val`. Updates if key exists, CREATES if it doesn't!
 * - at(key)            : Returns value. THROWS ERROR if key doesn't exist (Safer than []).
 * - find(key)          : Returns an iterator to the key, or `end()` if not found.
 * - erase(key)         : Deletes the key-value pair.
 * - count(key)         : Returns 1 if key exists, 0 if it doesn't (returns >1 in multimap).
 */

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

void demonstrateMap() {
    cout << "--- 1. std::map (Ordered & Unique Keys) ---\n";
    map<int, string> m;
    
    // Insertion
    m.insert({3, "Charlie"});
    m.insert({1, "Alice"});
    m[2] = "Bob"; // Using [] operator
    
    // Updating existing value
    m[1] = "Alice Updated"; 
    
    // Iteration (Notice it prints in SORTED order: 1, 2, 3)
    cout << "Map elements (Sorted by Key):\n";
    for (auto it = m.begin(); it != m.end(); ++it) {
        // it->first is the Key, it->second is the Value
        cout << "  Key: " << it->first << " | Value: " << it->second << "\n";
    }
    cout << "\n";
}

void demonstrateUnorderedMap() {
    cout << "--- 2. std::unordered_map (Unordered & Unique Keys, O(1) Time) ---\n";
    unordered_map<string, int> umap;
    
    umap["Apple"] = 100;
    umap["Banana"] = 50;
    umap["Cherry"] = 200;
    
    cout << "Unordered Map elements (Random Order):\n";
    for (auto pair : umap) { // Modern C++ range-based for loop
        cout << "  Key: " << pair.first << " | Value: " << pair.second << "\n";
    }
    
    // Using find() function
    string searchKey = "Banana";
    if (umap.find(searchKey) != umap.end()) {
        cout << searchKey << " found! Value: " << umap[searchKey] << "\n";
    } else {
        cout << searchKey << " NOT found!\n";
    }
    cout << "\n";
}

void demonstrateMultimap() {
    cout << "--- 3. std::multimap (Ordered & DUPLICATE Keys allowed) ---\n";
    multimap<int, string> mmap;
    
    mmap.insert({1, "Car"});
    mmap.insert({1, "Bike"}); // Duplicate key 1!
    mmap.insert({2, "Bus"});
    
    // mmap[1] = "Train"; // ❌ ERROR! operator[] is not allowed in multimap!
    
    cout << "Multimap elements (Notice duplicate Key 1):\n";
    for (auto it : mmap) {
        cout << "  Key: " << it.first << " | Value: " << it.second << "\n";
    }
    
    cout << "Count of Key 1: " << mmap.count(1) << " times.\n\n";
}

void interviewProTip() {
    cout << "--- 4. INTERVIEW PRO TIP: The Danger of operator[] ---\n";
    
    map<int, string> dangerMap;
    dangerMap[1] = "One";
    
    cout << "Initial size: " << dangerMap.size() << "\n";
    
    /* 
    If you use `[]` to search for a key that DOES NOT EXIST, it will SILENTLY 
    create that key with a default value (e.g., empty string or 0). 
    This can cause huge logical bugs in your code!
    */
    if (dangerMap[99] == "Missing") { 
        // We are just checking, but [] creates the key 99!
    }
    
    cout << "Size after checking dangerMap[99]: " << dangerMap.size() << " (Oops! It silently added Key 99!)\n";
    
    cout << "HOW TO FIX IT? Always use `.find(key) != map.end()` or `.count(key)` to check if a key exists!\n";
}

int main() {
    demonstrateMap();
    demonstrateUnorderedMap();
    demonstrateMultimap();
    interviewProTip();
    
    /*
    Summary of when to use what:
    - Need sorted keys? -> std::map (O(log N))
    - Need extremely fast lookups and don't care about order? -> std::unordered_map (O(1))
    - Need to store multiple values for the exact same key? -> std::multimap (O(log N))
    */
    
    return 0;
}
