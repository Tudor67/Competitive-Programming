class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();

        vector<int> delta(N + 1);

        int qIdx = 0;
        for(int i = 0; i < N; ++i){
            if(i >= 1){
                delta[i] += delta[i - 1];
            }

            while(qIdx < Q && delta[i] < nums[i]){
                int l = queries[qIdx][0];
                int r = queries[qIdx][1];
                int val = queries[qIdx][2];

                if(i <= r){
                    delta[max(l, i)] += val;
                    delta[r + 1] -= val;
                }

                qIdx += 1;
            }

            if(delta[i] < nums[i]){
                return -1;
            }
        }

        return qIdx;
    }
};