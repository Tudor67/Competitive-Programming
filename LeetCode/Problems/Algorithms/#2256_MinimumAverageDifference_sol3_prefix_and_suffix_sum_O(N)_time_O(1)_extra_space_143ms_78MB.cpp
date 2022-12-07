class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        const int N = nums.size();
        const long long TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0LL);
        
        long long minDiff = TOTAL_SUM / N;
        int minDiffIndex = N - 1;
        
        long long prefSum = 0;
        long long suffSum = TOTAL_SUM;
        for(int i = 0; i < N - 1; ++i){
            prefSum += nums[i];
            suffSum -= nums[i];
            long long diff = abs(prefSum / (i + 1) - suffSum / (N - 1 - i));
            if(diff < minDiff || (diff == minDiff && i < minDiffIndex)){
                minDiff = diff;
                minDiffIndex = i;
            }
        }
        
        return minDiffIndex;
    }
};