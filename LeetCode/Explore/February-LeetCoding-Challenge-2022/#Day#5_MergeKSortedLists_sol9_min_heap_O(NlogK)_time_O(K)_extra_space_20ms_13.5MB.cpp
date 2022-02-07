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
        ListNode* prevHead = new ListNode();
        ListNode* prevNode = prevHead;
        
        using PIL = pair<int, ListNode*>;
        priority_queue<PIL, vector<PIL>, greater<PIL>> minHeap;
        for(ListNode* node: lists){
            if(node != NULL){
                minHeap.emplace(node->val, node);
            }
        }
        
        while(!minHeap.empty()){
            ListNode* node = minHeap.top().second;
            minHeap.pop();
            
            prevNode->next = node;
            prevNode = node;
            
            if(node->next != NULL){
                minHeap.emplace(node->next->val, node->next);
            }
        }
        
        ListNode* head = prevHead->next;
        prevHead->next = NULL;
        delete prevHead;
        
        return head;
    }
};