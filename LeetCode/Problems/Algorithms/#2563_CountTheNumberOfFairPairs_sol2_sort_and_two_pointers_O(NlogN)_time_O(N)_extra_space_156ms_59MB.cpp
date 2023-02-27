class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        long long res = 0;
        int lowIndex = N - 1;
        int upIndex = N - 1;
        
        for(int i = 0; i < N; ++i){
            lowIndex = max(lowIndex, i);
            while(lowIndex > i && sortedNums[i] + sortedNums[lowIndex] >= lower){
                lowIndex -= 1;
            }

            upIndex = max(upIndex, i);
            while(upIndex > i && sortedNums[i] + sortedNums[upIndex] > upper){
                upIndex -= 1;
            }

            res += (upIndex - lowIndex);
        }
        
        return res;
    }
};