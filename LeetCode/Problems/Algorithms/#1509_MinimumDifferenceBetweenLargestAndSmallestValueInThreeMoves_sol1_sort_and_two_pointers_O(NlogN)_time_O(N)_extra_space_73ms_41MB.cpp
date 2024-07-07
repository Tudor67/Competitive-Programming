class Solution {
public:
    int minDifference(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 4){
            return 0;
        }

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int minDiff = sortedNums.back() - sortedNums.front();
        for(int l = 0; l <= 3; ++l){
            int r = N - 4 + l;
            minDiff = min(minDiff, sortedNums[r] - sortedNums[l]);
        }

        return minDiff;
    }
};