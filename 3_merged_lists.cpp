/*
 Merge K Sorted Lists
Merge k sorted linked lists and return one sorted list.

Approach:
Use min-heap (priority queue) to merge lists efficiently.
Time Complexity: O(N log k)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode{
    int val; ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

struct compare{
    bool operator()(ListNode* a, ListNode* b){ return a->val>b->val; }
};

ListNode* mergeKLists(vector<ListNode*>& lists){
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    for(auto l:lists) if(l) pq.push(l);
    ListNode* dummy=new ListNode(0);
    ListNode* curr=dummy;
    while(!pq.empty()){
        ListNode* node=pq.top(); pq.pop();
        curr->next=node; curr=curr->next;
        if(node->next) pq.push(node->next);
    }
    return dummy->next;
}

int main(){
    ListNode* l1=new ListNode(1); l1->next=new ListNode(4); l1->next->next=new ListNode(5);
    ListNode* l2=new ListNode(1); l2->next=new ListNode(3); l2->next->next=new ListNode(4);
    ListNode* l3=new ListNode(2); l3->next=new ListNode(6);
    vector<ListNode*> lists={l1,l2,l3};
    ListNode* res=mergeKLists(lists);
    while(res){ cout<<res->val<<" "; res=res->next; }
    cout<<endl;
    return 0;
}
