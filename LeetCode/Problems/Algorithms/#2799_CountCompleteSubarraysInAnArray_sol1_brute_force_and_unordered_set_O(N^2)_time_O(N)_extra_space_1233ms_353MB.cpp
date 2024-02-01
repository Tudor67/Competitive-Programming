class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        const int N = nums.size();
        const int DISTINCT_NUMS = unordered_set<int>(nums.begin(), nums.end()).size();

        int res = 0;
        unordered_set<int> subarraySet;
        for(int i = 0; i < N; ++i){
            subarraySet.clear();
            for(int j = i; j < N; ++j){
                subarraySet.insert(nums[j]);
                if((int)subarraySet.size() == DISTINCT_NUMS){
                    res += 1;
                }
            }
        }

        return res;
    }
};