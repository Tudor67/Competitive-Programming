class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        const int N = nums.size();
        const int TOTAL_DISTINCT_NUMS = unordered_set<int>(nums.begin(), nums.end()).size();

        int res = 0;
        int l = 0;
        unordered_map<int, int> freq;
        for(int r = 0; r < N; ++r){
            freq[nums[r]] += 1;
            if((int)freq.size() == TOTAL_DISTINCT_NUMS){
                while(freq[nums[l]] >= 2){
                    freq[nums[l]] -= 1;
                    l += 1;
                }
                res += (l + 1);
            }
        }

        return res;
    }
};