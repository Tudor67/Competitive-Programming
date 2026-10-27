class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end(),
             [](int lhs, int rhs){
                return (lhs * lhs < rhs * rhs);
             });

        long long res = 0;
        for(int l = 0, r = N - 1; l < r; ++l, --r){
            res += (sortedNums[r] * sortedNums[r]);
            res -= (sortedNums[l] * sortedNums[l]);
        }

        if(N % 2 == 1){
            res += (sortedNums[N / 2] * sortedNums[N / 2]);
        }

        return res;
    }
};