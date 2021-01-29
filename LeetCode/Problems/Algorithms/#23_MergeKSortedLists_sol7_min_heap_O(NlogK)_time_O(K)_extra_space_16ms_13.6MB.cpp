/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i] != NULL){
                minHeap.push({lists[i]->val, lists[i]});
            }
        }
        
        ListNode* virtualHead = new ListNode();
        ListNode* tail = virtualHead;
        while(!minHeap.empty()){
            ListNode* node = minHeap.top().second;
            minHeap.pop();
            tail->next = node;
            tail = tail->next;
            if(node->next != NULL){
                minHeap.push({node->next->val, node->next});
            }
        }
        
        return virtualHead->next;
    }
};