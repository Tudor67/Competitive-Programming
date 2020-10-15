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
        for(ListNode* p = head; p != NULL; p = p->next){
            listSize += 1;
        }
        return listSize;
    }
    
    ListNode* next(ListNode* head, int distance = 1){
        ListNode* p = head;
        for(int i = 1; i <= distance; ++i){
            if(p == NULL){
                return NULL;
            }
            p = p->next;
        }
        return p;
    }
    
    void merge(ListNode* prevP1Start, ListNode* p1Start, ListNode* p1End, ListNode* p2Start, ListNode* p2End){
        ListNode* p = prevP1Start;
        ListNode* p1 = p1Start;
        ListNode* p2 = p2Start;
        
        while(p1 != p1End && p2 != p2End){
            if(p1->val < p2->val){
                p->next = p1;
                p = p->next;
                p1 = p1->next;
            }else{
                p->next = p2;
                p = p->next;
                p2 = p2->next;
            }
        }
        
        while(p1 != p1End){
            p->next = p1;
            p = p->next;
            p1 = p1->next;
        }
        
        while(p2 != p2End){
            p->next = p2;
            p = p->next;
            p2 = p2->next;
        }
        
        p->next = p2End;
    }
    
    void setSubListPointers(ListNode* prevP1Start, ListNode*& p1Start, ListNode*& p1End, ListNode*& p2Start, ListNode*& p2End, const int& SUB_LIST_SIZE){
        p1Start = next(prevP1Start, 1);
        p1End = next(p1Start, SUB_LIST_SIZE);
        p2Start = p1End;
        p2End = next(p2Start, SUB_LIST_SIZE);
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* virtualStart = new ListNode(0, head);
        ListNode* prevP1Start = virtualStart;
        ListNode* p1Start, *p1End;
        ListNode* p2Start, *p2End;
        
        int subListSize = 1;
        int listSize = getListSize(head);
        while(subListSize <= listSize){
            prevP1Start = virtualStart;
            while(prevP1Start != NULL){
                setSubListPointers(prevP1Start, p1Start, p1End, p2Start, p2End, subListSize);
                merge(prevP1Start, p1Start, p1End, p2Start, p2End);
                prevP1Start = next(prevP1Start, 2 * subListSize);
            }
            subListSize *= 2;
        }
        
        return virtualStart->next;
    }
};