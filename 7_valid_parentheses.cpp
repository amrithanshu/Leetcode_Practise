/*
Problem: Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:
1. Open brackets are closed by the same type of brackets.
2. Open brackets are closed in the correct order.

Approach:
- Use a stack to track opening brackets.
- When a closing bracket appears, check if it matches the top of the stack.
- If stack is empty or brackets don’t match, return false.
- After processing, stack must be empty for a valid string.
Time Complexity: O(n)
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(char c : s){
        if(c=='(' || c=='{' || c=='[') st.push(c);
        else{
            if(st.empty()) return false;
            if(c==')' && st.top()!='(') return false;
            if(c=='}' && st.top()!='{') return false;
            if(c==']' && st.top()!='[') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s = "({[]})";
    cout << (isValid(s) ? "True" : "False") << endl;

    string t = "([)]";
    cout << (isValid(t) ? "True" : "False") << endl;
    
    return 0;
}
