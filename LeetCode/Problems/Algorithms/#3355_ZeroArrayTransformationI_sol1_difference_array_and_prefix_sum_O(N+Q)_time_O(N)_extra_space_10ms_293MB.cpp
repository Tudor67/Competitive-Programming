class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();

        vector<int> delta(N + 1);
        for(vector<int>& query: queries){
            int l = query[0];
            int r = query[1];
            delta[l] += 1;
            delta[r + 1] -= 1;
        }

        int currOps = 0;
        for(int i = 0; i < N; ++i){
            currOps += delta[i];
            if(currOps < nums[i]){
                return false;
            }
        }

        return true;
    }
};