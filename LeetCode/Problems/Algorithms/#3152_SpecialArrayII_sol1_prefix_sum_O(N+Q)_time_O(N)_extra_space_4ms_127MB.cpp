class Solution {
private:
    int flippedParity(int a, int b){
        return ((a % 2) != (b % 2));
    }

    int getRangeSum(vector<int>& prefSum, int l, int r){
        if(l > r) return 0;
        if(l == 0) return prefSum[r];
        return (prefSum[r] - prefSum[l - 1]);
    }

public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();

        if(N == 1){
            return vector<bool>(Q, true);
        }

        vector<int> flippedPrefSum(N - 1);
        flippedPrefSum[0] = flippedParity(nums[0], nums[1]);
        for(int i = 1; i + 1 < N; ++i){
            flippedPrefSum[i] = flippedPrefSum[i - 1] + flippedParity(nums[i], nums[i + 1]);
        }

        vector<bool> res(Q);
        for(int i = 0; i < Q; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            res[i] = (r - l == getRangeSum(flippedPrefSum, l, r - 1));
        }

        return res;
    }
};