class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = -1;
        unordered_set<int> vis;
        for(int num: nums){
            if(vis.count(-num)){
                res = max(res, abs(num));
            }
            vis.insert(num);
        }
        return res;
    }
};