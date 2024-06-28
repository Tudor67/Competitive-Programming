class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        const int N = nums.size();

        int maxLen = 0;
        set<pair<int, int>> s;
        int l = 0;
        for(int r = 0; r < N; ++r){
            s.insert({nums[r], r});
            while(l <= r && s.rbegin()->first - s.begin()->first > limit){
                s.erase({nums[l], l});
                l += 1;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        
        return maxLen;
    }
};