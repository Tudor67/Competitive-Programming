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
    ListNode* merge2Lists(ListNode* A, ListNode* B){
        ListNode* prevHead = new ListNode();
        ListNode* tail = prevHead;

        while(A != nullptr || B != nullptr){
            if(B == nullptr || (A != nullptr && A->val <= B->val)){
                tail->next = A;
                A = A->next;
            }else{
                tail->next = B;
                B = B->next;
            }
            tail = tail->next;
        }

        ListNode* head = prevHead->next;
        prevHead->next = nullptr;
        delete prevHead;

        return head;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const int K = lists.size();

        if(K == 0){
            return nullptr;
        }

        for(int step = 1; step < K; step *= 2){
            for(int i = 0; i + step < K; i += 2 * step){
                lists[i] = merge2Lists(lists[i], lists[i + step]);
            }
        }

        return lists[0];
    }
};