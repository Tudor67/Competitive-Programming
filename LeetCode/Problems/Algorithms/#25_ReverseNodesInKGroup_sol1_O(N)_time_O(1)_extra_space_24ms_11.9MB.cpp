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
    int getListSize(ListNode* head){
        int listSize = 0;
        for(ListNode* node = head; node != NULL; node = node->next){
            listSize += 1;
        }
        return listSize;
    }
    
    pair<ListNode*, ListNode*> reverseSublist(ListNode* head, const int& K){
        ListNode* tailPredecessor = head;
        ListNode* tail = head->next;
        ListNode* tailSuccessor = NULL;
        for(int i = 1; i <= K - 1; ++i){
            tailSuccessor = tail->next;
            tail->next = tailPredecessor;
            tailPredecessor = tail;
            tail = tailSuccessor;
        }
        tail = tailPredecessor;
        return {tail, tailSuccessor};
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int K) {
        if(K == 1){
            return head;
        }
        
        const int LIST_SIZE = getListSize(head);
        const int GROUPS = LIST_SIZE / K;
        
        // aux nodes
        ListNode* virtualHead = new ListNode(0, head);
        ListNode* headPredecessor = virtualHead;
        
        for(int group = 1; group <= GROUPS; ++group){
            // reverse sublist
            pair<ListNode*, ListNode*> p = reverseSublist(head, K);
            ListNode* tail = p.first;
            ListNode* tailSuccessor = p.second;
            // update links/connections to the reversed sublist and update head for the next sublist
            headPredecessor->next = tail;
            head->next = tailSuccessor;
            headPredecessor = head;
            head = tailSuccessor;
        }
        
        return virtualHead->next;
    }
};