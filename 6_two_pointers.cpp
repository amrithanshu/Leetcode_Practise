/*
 Two Sum I - Input Array Is Sorted
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
find two numbers such that they add up to a specific target number.

Approach:
Use two pointers, one at start and one at end. Move pointers inward based on sum comparison.
Time Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left=0, right=numbers.size()-1;
    while(left<right){
        int sum = numbers[left]+numbers[right];
        if(sum==target) return {left+1, right+1}; // 1-indexed
        else if(sum<target) left++;
        else right--;
    }
    return {};
}

int main(){
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    vector<int> res = twoSum(numbers, target);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
