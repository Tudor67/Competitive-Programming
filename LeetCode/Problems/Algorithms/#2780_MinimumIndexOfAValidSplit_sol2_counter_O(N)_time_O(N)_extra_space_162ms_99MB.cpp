class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const int N = nums.size();

        unordered_map<int, int> f;
        for(int num: nums){
            f[num] += 1;
        }

        int dominant = nums[0];
        for(int num: nums){
            if(f[dominant] < f[num]){
                dominant = num;
            }
        }

        int dominantFreq = f[dominant];
        for(int i = 0; i < N - 1; ++i){
            f[nums[i]] -= 1;
            
            int leftSize = i + 1;
            int rightSize = N - leftSize;

            int leftDominantFreq = dominantFreq - f[dominant];
            int rightDominantFreq = f[dominant];
            
            if(leftDominantFreq * 2 > leftSize && rightDominantFreq * 2 > rightSize){
                return i;
            }
        }

        return -1;
    }
};