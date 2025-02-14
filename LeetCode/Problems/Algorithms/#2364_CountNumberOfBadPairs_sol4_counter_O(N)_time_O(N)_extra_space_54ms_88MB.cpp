class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        const int N = nums.size();

        long long badPairs = 0;
        unordered_map<int, int> freq;
        
        for(int i = 0; i < N; ++i){
            int diff = nums[i] - i;
            badPairs += (i - freq[diff]);
            freq[diff] += 1;
        }

        return badPairs;
    }
};