class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        const int N = nums.size();

        long long res = 0;
        int startIndex = -1;
        int minKIndex = -1;
        int maxKIndex = -1;

        for(int i = 0; i < N; ++i){
            if(nums[i] == minK){
                minKIndex = i;
            }
            if(nums[i] == maxK){
                maxKIndex = i;
            }
            if(nums[i] < minK || maxK < nums[i]){
                startIndex = i;
                minKIndex = i;
                maxKIndex = i;
            }
            res += min(minKIndex, maxKIndex) - startIndex;
        }

        return res;
    }
};