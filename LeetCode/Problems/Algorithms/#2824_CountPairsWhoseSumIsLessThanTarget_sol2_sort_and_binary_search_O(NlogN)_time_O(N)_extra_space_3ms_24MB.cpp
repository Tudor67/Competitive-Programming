class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int res = 0;
        for(int i = 0; i < N; ++i){
            int j = lower_bound(sortedNums.begin() + i + 1, sortedNums.end(), target - sortedNums[i])
                    - sortedNums.begin();
            res += (j - i - 1);
        }

        return res;
    }
};