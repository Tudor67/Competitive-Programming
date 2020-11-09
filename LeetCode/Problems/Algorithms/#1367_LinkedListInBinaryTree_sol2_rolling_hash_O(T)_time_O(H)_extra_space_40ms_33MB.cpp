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
    static const int MODULO = 667013;
    const int SIZE;
    const int BASE;
    vector<int> values;
    vector<int> hashValues;
    int maxPow;
    
    void fixMaxPow(){
        maxPow = 1;
        for(int i = 1; i <= SIZE - 1; ++i){
            maxPow = (maxPow * BASE) % MODULO;
        }
    }
    
public:
    RollingHash(const int& SIZE, const int& BASE): SIZE(SIZE), BASE(BASE){
        fixMaxPow();
    }
    
    RollingHash(const vector<int>& VALUES, const int& BASE): SIZE(VALUES.size()), BASE(BASE){
        fixMaxPow();
        for(const int& VAL: VALUES){
            pushBack(VAL);
        }
    }
    
    void pushBack(const int& VAL){
        values.push_back(VAL);
        int hashVal = (hashValues.empty() ? 0 : hashValues.back());
        if(values.size() >= SIZE){
            hashVal = (((hashVal - maxPow * values[(int)values.size() - SIZE]) % MODULO) + MODULO) % MODULO;
        }
        hashVal = (BASE * (hashVal + VAL)) % MODULO;
        hashValues.push_back(hashVal);
    }
    
    void popBack(){
        values.pop_back();
        hashValues.pop_back();
    }
    
    int getHash(){
        if(hashValues.size() >= SIZE){
            return hashValues.back();
        }
        return -1;
    }
};

class Solution {
private:
    bool matches(const vector<int>& VALUES, const vector<int>& TARGET_VALUES){
        for(int i = (int)VALUES.size() - 1, j = (int)TARGET_VALUES.size() - 1; j >= 0; --i, --j){
            if(VALUES[i] != TARGET_VALUES[j]){
                return false;
            }
        }
        return true;
    }
    
    void dfs(TreeNode* node, vector<int>& values,  const vector<int>& TARGET_VALUES,
             RollingHash& hashObj, const int& TARGET_HASH, bool& contains){     
        if(node == NULL || contains){
            return;
        }
        
        values.push_back(node->val);
        hashObj.pushBack(node->val);
        if(hashObj.getHash() == TARGET_HASH){
            contains = matches(values, TARGET_VALUES);
        }
        
        dfs(node->left, values, TARGET_VALUES, hashObj, TARGET_HASH, contains);
        dfs(node->right, values, TARGET_VALUES, hashObj, TARGET_HASH, contains);
        values.pop_back();
        hashObj.popBack();
    }
    
public:
    bool isSubPath(ListNode* head, TreeNode* root) {        
        vector<int> targetValues;
        for(ListNode* node = head; node != NULL; node = node->next){
            targetValues.push_back(node->val);
        }
        
        const int SIZE = targetValues.size();
        const int BASE = 101;
        const int TARGET_HASH = RollingHash(targetValues, BASE).getHash();
        
        vector<int> values;
        RollingHash hashObj(SIZE, BASE);
        bool contains = false;
        
        dfs(root, values, targetValues, hashObj, TARGET_HASH, contains);
        
        return contains;
    }
};