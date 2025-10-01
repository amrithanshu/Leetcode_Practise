/*
 Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, 
return the minimal length of a contiguous subarray of which the sum ≥ target. 
If there is no such subarray, return 0.

Approach:
Sliding window: expand window until sum ≥ target, shrink from left to minimize.
Time Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums){
    int sum=0, left=0, minLen=INT_MAX;
    for(int right=0; right<nums.size(); right++){
        sum+=nums[right];
        while(sum>=target){
            minLen=min(minLen, right-left+1);
            sum-=nums[left++];
        }
    }
    return minLen==INT_MAX?0:minLen;
}

int main(){
    vector<int> nums={2,3,1,2,4,3};
    int target=7;
    cout << minSubArrayLen(target, nums) << endl;
    return 0;
}
