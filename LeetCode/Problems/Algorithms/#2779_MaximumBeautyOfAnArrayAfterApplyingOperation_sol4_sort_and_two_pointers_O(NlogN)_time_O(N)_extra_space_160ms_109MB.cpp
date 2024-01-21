class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int res = 0;
        int l = 0;
        for(int r = 0; r < N; ++r){
            while(l <= r && sortedNums[l] + k < sortedNums[r] - k){
                l += 1;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};