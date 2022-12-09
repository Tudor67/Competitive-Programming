class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int validTriplets = 0;
        for(int j = 1; j + 1 < N; ++j){
            int i = lower_bound(sortedNums.begin(), sortedNums.end(), sortedNums[j]) - sortedNums.begin() - 1;
            int k = upper_bound(sortedNums.begin(), sortedNums.end(), sortedNums[j]) - sortedNums.begin();
            if(0 <= i && k < N){
                int leftCount = i + 1;
                int rightCount = N - k;
                validTriplets += leftCount * rightCount;
            }
        }

        return validTriplets;
    }
};