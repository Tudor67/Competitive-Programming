class Solution {
private:
    int getRangeCount(int l, int r, int num, vector<vector<int>>& prefCount){
        if(l > r){
            return 0;
        }
        if(l == 0){
            return prefCount[r][num];
        }
        return prefCount[r][num] - prefCount[l - 1][num];
    }

public:
    int minimumOperations(vector<int>& nums) {
        const int N = nums.size();

        vector<vector<int>> prefCount(N, vector<int>(4));
        for(int i = 0; i < N; ++i){
            if(i >= 1){
                prefCount[i] = prefCount[i - 1];
            }
            prefCount[i][nums[i]] += 1;
        }

        int minOps = N;
        for(int c1 = 0; c1 <= N; ++c1){
            for(int c2 = 0; c2 <= N - c1; ++c2){
                int c3 = N - c1 - c2;
                int ops1 = c1 - getRangeCount(0, c1 - 1, 1, prefCount);
                int ops2 = c2 - getRangeCount(c1, c1 + c2 - 1, 2, prefCount);
                int ops3 = c3 - getRangeCount(c1 + c2, N - 1, 3, prefCount);
                minOps = min(minOps, ops1 + ops2 + ops3);
            }
        }

        return minOps;
    }
};