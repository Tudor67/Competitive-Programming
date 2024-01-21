class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int res = 0;
        for(int i = 0; i < N; ++i){
            int j = upper_bound(sortedNums.begin() + i, sortedNums.end(), sortedNums[i] + 2 * k) - sortedNums.begin();
            res = max(res, j - i);
        }

        return res;
    }
};