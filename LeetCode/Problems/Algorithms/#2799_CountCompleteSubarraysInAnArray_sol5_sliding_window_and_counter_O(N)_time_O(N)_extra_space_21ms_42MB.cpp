class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        const int N = nums.size();
        const int TOTAL_DISTINCT = unordered_set<int>(nums.begin(), nums.end()).size();

        int completeSubarrays = 0;
        unordered_map<int, int> f;
        
        int l = 0;
        for(int r = 0; r < N; ++r){
            f[nums[r]] += 1;
            while(f[nums[l]] >= 2){
                f[nums[l]] -= 1;
                l += 1;
            }

            if((int)f.size() == TOTAL_DISTINCT){
                completeSubarrays += (l + 1);
            }
        }

        return completeSubarrays;
    }
};