class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        const int N = nums.size();
        
        int count = 0;
        long long prefSum = 0;
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        for(int i = 0; i < N - 1; ++i){
            prefSum += nums[i];
            if(prefSum >= totalSum - prefSum){
                count += 1;
            }
        }
        
        return count;
    }
};