class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        const int N = nums.size();
        
        unordered_set<int> vis;
        for(int i = 0; i + 1 < N; ++i){
            int sum = nums[i] + nums[i + 1];
            if(vis.count(sum)){
                return true;
            }
            vis.insert(sum);
        }
        
        return false;
    }
};