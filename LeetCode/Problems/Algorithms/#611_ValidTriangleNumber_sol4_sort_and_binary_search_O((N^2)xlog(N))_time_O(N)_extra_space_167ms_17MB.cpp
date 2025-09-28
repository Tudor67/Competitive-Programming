class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int validTriplets = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                int k = lower_bound(sortedNums.begin() + j + 1, sortedNums.end(),
                                    sortedNums[i] + sortedNums[j]) - sortedNums.begin();
                validTriplets += (k - j - 1);
            }
        }

        return validTriplets;
    }
};