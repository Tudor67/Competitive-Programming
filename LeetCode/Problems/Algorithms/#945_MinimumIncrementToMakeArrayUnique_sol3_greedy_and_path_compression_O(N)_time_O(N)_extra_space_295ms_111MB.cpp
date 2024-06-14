class Solution {
private:
    int find(int x, unordered_map<int, int>& root){
        if(root.count(x)){
            root[x] = find(root[x] + 1, root);
        }else{
            root[x] = x;
        }
        return root[x];
    }

public:
    int minIncrementForUnique(vector<int>& nums) {
        int minOps = 0;
        unordered_map<int, int> root;
        for(int num: nums){
            minOps += find(num, root) - num;
        }
        return minOps;
    }
};