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
        const int K = lists.size();
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;
        for(int i = 0; i < K; ++i){
            if(lists[i] != nullptr){
                minHeap.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* prevHead = new ListNode();
        ListNode* tail = prevHead;
        while(!minHeap.empty()){
            ListNode* node = minHeap.top().second;
            minHeap.pop();

            tail->next = node;
            tail = tail->next;

            if(node->next != nullptr){
                minHeap.push({node->next->val, node->next});
            }
        }

        ListNode* head = prevHead->next;
        prevHead->next = nullptr;
        delete prevHead;

        return head;
    }
};