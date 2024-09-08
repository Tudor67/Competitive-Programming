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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class RollingHash{
private:
    const long long BASE;
    const long long MODULO;
    vector<long long> v;
    vector<long long> h;
    vector<long long> p;

public:
    RollingHash(const long long BASE, const long long MODULO): BASE(BASE), MODULO(MODULO){

    }

    void pushBack(long long val){
        if(h.empty()){
            v.push_back(val);
            h.push_back(val);
            p.push_back(1);
        }else{
            v.push_back(val);
            h.push_back((h.back() * BASE + val) % MODULO);
            p.push_back((p.back() * BASE) % MODULO);
        }
    }

    void popBack(){
        v.pop_back();
        h.pop_back();
        p.pop_back();
    }

    long long getSize(){
        return h.size();
    }

    long long getHash(){
        return h.back();
    }

    long long getHash(int l, int r){
        if(l > r){
            return -1;
        }
        if(l == 0){
            return h[r];
        }
        return (h[r] - h[l - 1] * p[r - (l - 1)] % MODULO + MODULO) % MODULO;
    }

    bool isMatching(int l, int r, RollingHash& otherRH){
        if(l < 0 || r - l + 1 != otherRH.getSize()){
            return false;
        }
        return (getHash(l, r) == otherRH.getHash() &&
                equal(v.begin() + l, v.begin() + r + 1, otherRH.v.begin()));
    }
};

class Solution {
private:
    bool isSubPath(TreeNode* node, RollingHash& treeRH, RollingHash& listRH){
        if(node == nullptr){
            return false;
        }
        treeRH.pushBack(node->val);
        bool found = treeRH.isMatching((int)treeRH.getSize() - (int)listRH.getSize(),
                                       (int)treeRH.getSize() - 1, listRH) ||
                     isSubPath(node->left, treeRH, listRH) ||
                     isSubPath(node->right, treeRH, listRH);
        treeRH.popBack();
        return found;
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        const long long BASE = 101;
        const long long MODULO = 1e9 + 7;

        RollingHash treeRH(BASE, MODULO);
        RollingHash listRH(BASE, MODULO);
        for(ListNode* node = head; node != nullptr; node = node->next){
            listRH.pushBack(node->val);
        }

        return isSubPath(root, treeRH, listRH);
    }
};