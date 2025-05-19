class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = 1e9;

        int minLen = INF;
        for(int i = 0; i < N; ++i){
            int rangeOR = 0;
            for(int j = i; j < N; ++j){
                rangeOR |= nums[j];
                if(rangeOR >= k){
                    minLen = min(minLen, j - i + 1);
                }
            }
        }

        if(minLen == INF){
            minLen = -1;
        }

        return minLen;
    }
};