/**
 * @file stack.cpp
 * @brief Comprehensive Guide to std::stack in C++ STL
 * 
 * WHAT IS A STACK?
 * A Stack is a LIFO (Last-In, First-Out) data structure. 
 * Imagine a stack of plates in a cafeteria: the last plate you put on the top is 
 * the first one you pick up. You cannot take a plate from the middle or the bottom 
 * without removing the ones above it.
 * 
 * IS IT A TRUE CONTAINER? (Important Interview Question)
 * No! `std::stack` is actually a "Container Adapter". 
 * This means it doesn't manage its own memory architecture. Instead, it wraps an 
 * existing sequence container (like `deque`, `vector`, or `list`) and restricts 
 * how you can access the data (forces LIFO rule).
 * By default, `std::stack` uses `std::deque` under the hood!
 * 
 * WHEN TO USE A STACK? (Real-world Use Cases)
 * 1. Undo/Redo Mechanisms (Text editors, Photoshop).
 * 2. Browser History (Going back to the previous page).
 * 3. Function Call Stack (How recursion and normal functions work in memory).
 * 4. Parentheses Matching / Syntax Parsing in compilers.
 * 5. Depth First Search (DFS) algorithms in graphs/trees.
 * 
 * FREQUENTLY USED FUNCTIONS:
 * - push(val) : Adds an element to the top. (O(1))
 * - emplace() : Constructs an element directly at the top (slightly faster than push). (O(1))
 * - pop()     : Removes the top element. DOES NOT return it! (O(1))
 * - top()     : Returns the value of the top element. (O(1))
 * - size()    : Returns the total number of elements. (O(1))
 * - empty()   : Returns true if the stack has no elements. (O(1))
 */

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

void demonstrateBasicStack() {
    cout << "--- 1. Basic Stack Operations (LIFO) ---\n";
    
    stack<int> s;
    
    // Pushing elements
    cout << "Pushing 10, 20, 30 onto the stack...\n";
    s.push(10);
    s.push(20);
    s.push(30); // 30 is now at the TOP
    
    cout << "Current Size: " << s.size() << "\n";
    cout << "Top Element : " << s.top() << "\n\n"; // Output: 30
    
    // Popping elements
    cout << "Popping the top element...\n";
    s.pop(); 
    /* 
    CRITICAL NOTE: `pop()` just deletes the top element. It does NOT return the value.
    If you want to use the top value and then remove it, you must do:
    int val = s.top();
    s.pop();
    */
    
    cout << "New Top Element: " << s.top() << "\n\n"; // Output: 20
}

void demonstrateStackIteration() {
    cout << "--- 2. How to 'Iterate' through a Stack ---\n";
    
    stack<string> browserHistory;
    browserHistory.push("google.com");
    browserHistory.push("facebook.com");
    browserHistory.push("youtube.com");
    
    /*
    CRITICAL RULE:
    Stacks DO NOT have iterators (`begin()`, `end()`). You cannot use a `for` loop 
    or pointer arithmetic to print a stack. The ONLY way to read all elements is 
    to continuously look at the `top()` and then `pop()` it until the stack is empty.
    */
    
    cout << "Browser History (Most recent first):\n";
    while (!browserHistory.empty()) {
        cout << "  -> " << browserHistory.top() << "\n";
        browserHistory.pop(); // Remove the top to access the one below it
    }
    cout << "\n";
}

void demonstrateUnderlyingContainer() {
    cout << "--- 3. Changing the Underlying Container (Advanced) ---\n";
    
    // By default, `stack<int>` is actually `stack<int, deque<int>>`.
    // But what if we strictly want our stack to use a Vector under the hood instead?
    
    stack<int, vector<int>> vectorStack;
    
    vectorStack.push(100);
    vectorStack.push(200);
    
    cout << "Stack using a Vector under the hood. Top: " << vectorStack.top() << "\n\n";
}

void demonstrateSwapAndEmplace() {
    cout << "--- 4. Swap and Emplace Functions ---\n";
    
    stack<string> s1, s2;
    
    // emplace() is like push(), but slightly faster because it constructs the object 
    // directly in the stack's memory, avoiding an extra copy operation.
    s1.emplace("Hello");
    s1.emplace("World");
    
    s2.push("C++");
    s2.push("STL");
    
    cout << "Before swap - s1 top: " << s1.top() << " | s2 top: " << s2.top() << "\n";
    
    // swap() exchanges the contents of two stacks instantly in O(1) time
    s1.swap(s2);
    
    cout << "After swap  - s1 top: " << s1.top() << " | s2 top: " << s2.top() << "\n\n";
}

void demonstrateEmptyStackDanger() {
    cout << "--- 5. The Danger of Empty Stacks ---\n";
    
    stack<int> s;
    
    /*
    ❌ CRITICAL WARNING:
    If you call `s.top()` or `s.pop()` on an empty stack, your program will CRASH 
    (Undefined Behavior). C++ does not check if the stack is empty for you!
    
    Always, ALWAYS check if the stack is empty before accessing the top!
    */
    
    if (!s.empty()) {
        cout << "Top element is: " << s.top() << "\n";
    } else {
        cout << "Stack is empty! Cannot call top() or pop() safely.\n\n";
    }
}

int main() {
    demonstrateBasicStack();
    demonstrateStackIteration();
    demonstrateUnderlyingContainer();
    demonstrateSwapAndEmplace();
    demonstrateEmptyStackDanger();
    
    /*
    Summary: 
    Stack is incredibly fast because all operations happen at exactly one place: the TOP. 
    Never try to access elements in the middle of a stack. If you need middle access, 
    you are using the wrong data structure and should switch to a Vector or Deque!
    */
    
    return 0;
}
