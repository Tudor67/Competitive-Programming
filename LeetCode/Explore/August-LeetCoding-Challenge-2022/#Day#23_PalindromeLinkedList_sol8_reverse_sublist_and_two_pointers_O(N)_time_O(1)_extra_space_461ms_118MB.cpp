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
    int computeListSize(ListNode* head){
        int listSize = 0;
        for(ListNode* node = head; node != nullptr; node = node->next){
            listSize += 1;
        }
        return listSize;
    }
    
    ListNode* nextElement(ListNode* head, int k){
        ListNode* node = head;
        for(int step = 1; step <= k; ++step){
            node = node->next;
        }
        return node;
    }
    
    ListNode* reverseList(ListNode* currentNode){
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;
        while(currentNode != nullptr){
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        return prevNode;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }
        
        int listSize = computeListSize(head);
        ListNode* midNode = nextElement(head, (listSize + 1) / 2);
        
        ListNode* tail = reverseList(midNode);
        
        ListNode* p1 = head;
        ListNode* p2 = tail;
        bool isPalindrome = true;
        for(int step = 1; step <= listSize / 2; ++step){
            if(p1->val != p2->val){
                isPalindrome = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        reverseList(tail);
        
        return isPalindrome;
    }
};