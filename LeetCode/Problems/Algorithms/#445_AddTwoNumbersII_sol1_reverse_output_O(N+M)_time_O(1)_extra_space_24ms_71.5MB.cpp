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
    int getListSize(ListNode* listHead){
        int listSize = 0;
        for(ListNode* node = listHead; node != NULL; node = node->next){
            listSize += 1;
        }
        return listSize;
    }
    
    ListNode* reverseList(ListNode* listHead){
        ListNode* prevNode = NULL;
        ListNode* node = listHead;
        while(node != NULL){
            ListNode* temp = node->next;
            node->next = prevNode;
            prevNode = node;
            node = temp;
        }
        return prevNode;
    }
    
    void insertNewNode(int num, ListNode*& nextNode){
        ListNode* newNode = new ListNode(num);
        newNode->next = nextNode;
        nextNode = newNode;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL;
        
        // Step 1
        int l1Pos = getListSize(l1);
        int l2Pos = getListSize(l2);
        while(l1Pos > 0 && l2Pos > 0){
            if(l1Pos > l2Pos){
                insertNewNode(l1->val, l3);
                l1 = l1->next;
                l1Pos -= 1;
            }else if(l1Pos < l2Pos){
                insertNewNode(l2->val, l3);
                l2 = l2->next;
                l2Pos -= 1;
            }else if(l1Pos == l2Pos){
                insertNewNode(l1->val + l2->val, l3);
                l1 = l1->next;
                l2 = l2->next;
                l1Pos -= 1;
                l2Pos -= 1;
            }
        }
        
        // Step 2
        int carry = 0;
        for(ListNode* node = l3; node != NULL; node = node->next){
            carry += node->val;
            node->val = carry % 10;
            carry /= 10;
            if(node->next == NULL && carry > 0){
                node->next = new ListNode(0);
            }
        }
        
        // Step 3
        ListNode* l3Head = reverseList(l3);
        
        return l3Head;
    }
};