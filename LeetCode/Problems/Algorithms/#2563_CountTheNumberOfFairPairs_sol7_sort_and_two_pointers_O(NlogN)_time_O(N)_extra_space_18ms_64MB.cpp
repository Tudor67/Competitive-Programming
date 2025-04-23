class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        long long fairPairs = 0;
        int lowerIndex = N - 1;
        int upperIndex = N - 1;
        for(int i = 0; i < N; ++i){
            lowerIndex = max(i, lowerIndex);
            while(i < lowerIndex && sortedNums[i] + sortedNums[lowerIndex] >= lower){
                lowerIndex -= 1;
            }
            while(i < upperIndex && sortedNums[i] + sortedNums[upperIndex] > upper){
                upperIndex -= 1;
            }
            if(i < upperIndex){
                fairPairs += (upperIndex - lowerIndex);
            }
        }

        return fairPairs;
    }
};