class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        const int N = nums.size();
        
        unordered_map<int, int> count;
        for(int i = 0; i < N; ++i){
            count[nums[i]] += 1;
            if(i >= k + 1){
                count[nums[i - (k + 1)]] -= 1;
                if(count[nums[i - (k + 1)]] == 0){
                    count.erase(nums[i - (k + 1)]);
                }
            }
            if(count[nums[i]] >= 2){
                return true;
            }
        }
        
        return false;
    }
};