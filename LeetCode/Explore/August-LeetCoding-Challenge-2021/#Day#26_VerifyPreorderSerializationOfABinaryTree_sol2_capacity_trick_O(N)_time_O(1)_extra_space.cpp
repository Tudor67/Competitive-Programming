class Solution {
public:
    bool isValidSerialization(string preorder) {
        const int N = preorder.size();
        int capacity = 1; // capacity is the number of nodes we can insert in the tree
        int i = 0;
        while(i < N){
            capacity -= 1; // we insert a new node (NULL or non-NULL) => capacity decreases by 1
            if(preorder[i] == '#'){
                i += 2;
            }else{
                while(i < N && isdigit(preorder[i])){
                    i += 1;
                }
                i += 1;
                capacity += 2; // the inserted node is non-NULL => capacity increases by 2 (space for 2 children)
            }
            if(capacity < 0 || (capacity == 0 && i < N)){
                // negative capacity => too many NULL nodes for this part of the tree => return false
                // capacity == 0 and i < N (i.e., we still have nodes to insert) => the tree is not connected => return false
                return false;
            }
        }
        // final capacity == 0 => we filled the tree with correct number of NULL and non-NULL nodes => return true
        return (capacity == 0);
    }
};