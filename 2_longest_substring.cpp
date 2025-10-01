/*
 Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.

Approach:
Use sliding window with hash set to track unique characters.
Time Complexity: O(n)
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s){
    unordered_set<char> set;
    int left=0, maxLen=0;
    for(int right=0; right<s.size(); right++){
        while(set.find(s[right])!=set.end())
            set.erase(s[left++]);
        set.insert(s[right]);
        maxLen = max(maxLen, right-left+1);
    }
    return maxLen;
}

int main(){
    string s="abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
