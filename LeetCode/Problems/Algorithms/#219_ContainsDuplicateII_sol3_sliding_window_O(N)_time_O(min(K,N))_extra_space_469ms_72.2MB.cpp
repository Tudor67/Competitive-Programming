class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int N = nums.size();
        
        unordered_set<int> vis;
        for(int i = 0; i < N; ++i){
            if(i >= k + 1){
                vis.erase(nums[i - (k + 1)]);
            }
            if(vis.count(nums[i])){
                return true;
            }
            vis.insert(nums[i]);
        }
        
        return false;
    }
};