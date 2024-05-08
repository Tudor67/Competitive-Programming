class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxK = -1;
        
        unordered_set<int> vis;
        for(int num: nums){
            if(vis.count(-num)){
                maxK = max(maxK, max(-num, num));
            }
            vis.insert(num);
        }

        return maxK;
    }
};