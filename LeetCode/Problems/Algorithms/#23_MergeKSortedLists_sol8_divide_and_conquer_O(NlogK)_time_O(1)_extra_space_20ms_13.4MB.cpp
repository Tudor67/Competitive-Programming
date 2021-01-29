/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    void merge2Lists(ListNode*& l1, ListNode*& l2){
        ListNode* virtualHead = new ListNode();
        ListNode* tail = virtualHead;
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        if(l1 == NULL){
            tail->next = l2;
        }else{
            tail->next = l1;
        }
        
        l1 = virtualHead->next;
        delete virtualHead;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int stepSize = 1; stepSize < lists.size(); stepSize *= 2){
            for(int i = 0; i + stepSize < lists.size(); i += 2 * stepSize){
                merge2Lists(lists[i], lists[i + stepSize]);
            }
        }
        return (lists.empty() ? NULL : lists[0]);
    }
};