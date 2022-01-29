class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int N = nums.size();
        
        unordered_map<int, int> lastPosOf;
        for(int i = 0; i < N; ++i){
            if(lastPosOf.count(nums[i]) && i - lastPosOf[nums[i]] <= k){
                return true;
            }
            if(i >= k + 1){
                lastPosOf.erase(nums[i - (k + 1)]);
            }
            lastPosOf[nums[i]] = i;
        }
        
        return false;
    }
};