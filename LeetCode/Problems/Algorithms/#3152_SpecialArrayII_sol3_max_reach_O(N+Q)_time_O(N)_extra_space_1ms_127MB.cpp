class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();

        vector<int> maxReach(N);
        maxReach[N - 1] = N - 1;
        for(int i = N - 2; i >= 0; --i){
            if((nums[i] % 2) == (nums[i + 1] % 2)){
                maxReach[i] = i;
            }else{
                maxReach[i] = maxReach[i + 1];
            }
        }

        vector<bool> res(Q);
        for(int i = 0; i < Q; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            res[i] = (maxReach[l] >= r);
        }

        return res;
    }
};