/*
 Top K Frequent Elements
Given a non-empty array of integers, return the k most frequent elements.

Approach:
Use hashmap to count frequency, then max-heap (priority queue) to get top k.
Time Complexity: O(n log k)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k){
    unordered_map<int,int> freq;
    for(int n: nums) freq[n]++;
    priority_queue<pair<int,int>> pq;
    for(auto &p: freq) pq.push({p.second,p.first});
    vector<int> res;
    for(int i=0;i<k;i++){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

int main(){
    vector<int> nums={1,1,1,2,2,3};
    int k=2;
    vector<int> res=topKFrequent(nums,k);
    for(int n:res) cout<<n<<" ";
    cout<<endl;
    return 0;
}
