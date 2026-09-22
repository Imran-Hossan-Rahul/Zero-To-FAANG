/**
 * @file practice-stl-pair.cpp
 * @brief Comprehensive Guide to std::pair in C++ STL
 * 
 * WHAT IS A PAIR?
 * A `std::pair` is a simple container defined in the `<utility>` header (though often 
 * included implicitly via `<vector>` or `<iostream>`).
 * It is used to combine together exactly TWO values that may be of different data types.
 * 
 * WHY USE PAIR?
 * 1. Returning Multiple Values: Functions in C++ can normally only return one value. If you need 
 *    to return two related values (like a status code and an error message), `pair` is the best choice.
 * 2. Mapping Data: It is heavily used in maps and graphs (e.g., storing a graph node and its weight).
 * 3. Grouping: Whenever two pieces of data are strongly related (e.g., X and Y coordinates, Name and Age).
 * 
 * HOW TO ACCESS VALUES?
 * You can access the first element using `.first` and the second element using `.second`.
 */

#include <iostream>
#include <vector>
#include <utility> // Best practice to explicitly include this when using std::pair
#include <string>

using namespace std;

void basicPairDemonstration() {
    cout << "--- 1. Basic Pair Initialization & Access ---\n";
    
    // 1. Initializing using Uniform Initialization (Modern C++ Best Practice)
    pair<int, int> p1 = {2, 5};
    cout << "p1: {" << p1.first << ", " << p1.second << "}\n";
    
    // 2. Pair with Mixed Data Types
    pair<int, string> p2 = {3, "nothing"};
    cout << "p2: {" << p2.first << ", " << p2.second << "}\n";
    
    // 3. Pair of Characters
    pair<char, char> p3 = {'C', 'D'};
    cout << "p3: {" << p3.first << ", " << p3.second << "}\n\n";
    
    // 4. Using make_pair() (Older C++ style, but still widely used)
    pair<string, double> p_make = make_pair("Pi", 3.14159);
    cout << "make_pair: {" << p_make.first << ", " << p_make.second << "}\n\n";
}

void nestedPairDemonstration() {
    cout << "--- 2. Nested Pairs (Pair inside a Pair) ---\n";
    
    /*
    Sometimes you need to store more than 2 related items. You can nest pairs!
    Here we have a pair where:
      - The `first` element is ANOTHER pair <int, string>
      - The `second` element is ANOTHER pair <int, int>
    */
    pair<pair<int, string>, pair<int, int>> p4 = {{4, "nothing"}, {3, 5}};
    
    // How to access nested pairs? We chain `.first` and `.second`!
    cout << "Nested Pair p4:\n";
    cout << "  First Pair -> First Element  : " << p4.first.first << "\n";      // Output: 4
    cout << "  First Pair -> Second Element : " << p4.first.second << "\n";     // Output: "nothing"
    cout << "  Second Pair -> First Element : " << p4.second.first << "\n";     // Output: 3
    cout << "  Second Pair -> Second Element: " << p4.second.second << "\n\n";  // Output: 5
}

void vectorOfPairsDemonstration() {
    cout << "--- 3. Vector of Pairs (Very Common in Competitive Programming) ---\n";
    
    // Let's create a vector that stores pairs of integers (e.g., 2D Graph Coordinates X, Y)
    vector<pair<int, int>> coordinates = {{1, 2}, {3, 4}, {5, 6}};
    
    cout << "Simple Vector of Pairs:\n";
    for(int i = 0; i < coordinates.size(); i++) {
        cout << "  Point " << i << ": X=" << coordinates[i].first << ", Y=" << coordinates[i].second << "\n";
    }
    cout << "\n";
    
    /*
    COMPLEX EXAMPLE: Vector of Nested Pairs
    This is what you had in your original code.
    It's a vector where each element is a pair of two pairs.
    Data structure: vector < pair < pair<int, string>, pair<int, int> > >
    */
    vector<pair<pair<int, string>, pair<int, int>>> complexVec = {
        {{4, "nothing"}, {3, 5}}, 
        {{9, "something"}, {7, 8}}
    };
    
    cout << "Complex Vector of Nested Pairs:\n";
    for(int i = 0; i < complexVec.size(); i++) {
        cout << "  Index " << i << ":\n";
        cout << "    Val1: " << complexVec[i].first.first << "\n";
        cout << "    Val2: " << complexVec[i].first.second << "\n";
        cout << "    Val3: " << complexVec[i].second.first << "\n";
        cout << "    Val4: " << complexVec[i].second.second << "\n";
    }
}

int main() {
    basicPairDemonstration();
    nestedPairDemonstration();
    vectorOfPairsDemonstration();
    
    /*
    PROFESSIONAL TIP:
    While heavily nested pairs like `pair<pair<A, B>, pair<C, D>>` work perfectly fine 
    technically, they become very hard to read and manage in large software projects 
    because of the constant chaining of `.first.first`.
    
    If you need to group 3 or more related items together in real-world professional code, 
    it is almost always better to create a `struct` or `class` instead of heavily nested pairs.
    It makes your code much cleaner and your intentions obvious!
    */
    
    return 0;
}