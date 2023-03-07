class Solution {
private:
    long long computeContrib(int firstIndex, int lastIndex, vector<int>& nums, int minK, int maxK){
        long long contrib = 0;
        
        int r = firstIndex - 1;
        int minKCount = 0;
        int maxKCount = 0;
        for(int l = firstIndex; l <= lastIndex; ++l){
            while(r + 1 <= lastIndex && (minKCount == 0 || maxKCount == 0)){
                minKCount += (int)(nums[r + 1] == minK);
                maxKCount += (int)(nums[r + 1] == maxK);
                r += 1;
            }
            if(minKCount >= 1 && maxKCount >= 1){
                contrib += (lastIndex - r + 1);
            }
            minKCount -= (int)(nums[l] == minK);
            maxKCount -= (int)(nums[l] == maxK);
        }

        return contrib;
    }

public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        const int N = nums.size();

        long long res = 0;

        int firstIndex = 0;
        while(firstIndex < N){
            int lastIndex = firstIndex - 1;
            while(lastIndex + 1 < N && minK <= nums[lastIndex + 1] && nums[lastIndex + 1] <= maxK){
                lastIndex += 1;
            }
            res += computeContrib(firstIndex, lastIndex, nums, minK, maxK);
            firstIndex = lastIndex + 2;
        }

        return res;
    }
};