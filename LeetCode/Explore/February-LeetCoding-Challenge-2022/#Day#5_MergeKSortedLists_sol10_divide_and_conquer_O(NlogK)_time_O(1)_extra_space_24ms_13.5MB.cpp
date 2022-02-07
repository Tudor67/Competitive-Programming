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
private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){        
        ListNode* prevHead = new ListNode();
        ListNode* prevNode = prevHead;
        
        while(l1 != NULL || l2 != NULL){
            if(l2 == NULL || (l1 != NULL && l1->val <= l2->val)){
                prevNode->next = l1;
                l1 = l1->next;
            }else{
                prevNode->next = l2;
                l2 = l2->next;
            }
            prevNode = prevNode->next;
        }
        
        ListNode* head = prevHead->next;
        prevHead->next = NULL;
        delete prevHead;
        
        return head;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        
        const int K = lists.size();
        for(int len = 2; len / 2 < K; len *= 2){
            for(int i = 0; i + len / 2 < K; i += len){
                lists[i] = merge2Lists(lists[i], lists[i + len / 2]);
            }
        }
        
        return lists[0];
    }
};