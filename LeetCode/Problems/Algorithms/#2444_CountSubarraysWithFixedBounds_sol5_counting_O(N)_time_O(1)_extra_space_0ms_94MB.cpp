class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        const int N = nums.size();

        long long validSubarrays = 0;

        int startPos = 0;
        int minKPos = N;
        int maxKPos = N;

        for(int i = 0; i < N; ++i){
            if(nums[i] < minK || maxK < nums[i]){
                minKPos = N;
                maxKPos = N;
                startPos = i + 1;
            }else{
                if(minK == nums[i]){
                    minKPos = i;
                }
                if(maxK == nums[i]){
                    maxKPos = i;
                }
                if(minKPos <= i && maxKPos <= i){
                    validSubarrays += (min(minKPos, maxKPos) - startPos + 1);
                }
            }
        }

        return validSubarrays;
    }
};