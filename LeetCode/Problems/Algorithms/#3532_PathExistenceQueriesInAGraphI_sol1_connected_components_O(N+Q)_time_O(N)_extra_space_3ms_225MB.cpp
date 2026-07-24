class Solution {
public:
    vector<bool> pathExistenceQueries(int N, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        const int Q = queries.size();

        vector<int> ccId(N);
        for(int i = 1; i < N; ++i){
            if(nums[i] - nums[i - 1] <= maxDiff){
                ccId[i] = ccId[i - 1];
            }else{
                ccId[i] = ccId[i - 1] + 1;
            }
        }

        vector<bool> res(Q);
        for(int i = 0; i < Q; ++i){
            int a = queries[i][0];
            int b = queries[i][1];
            res[i] = (ccId[a] == ccId[b]);
        }

        return res;
    }
};