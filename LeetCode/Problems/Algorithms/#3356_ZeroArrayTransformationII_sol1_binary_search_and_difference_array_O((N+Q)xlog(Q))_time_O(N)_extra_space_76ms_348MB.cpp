class Solution {
private:
    bool isPossible(vector<int>& nums, vector<vector<int>>& queries, int k){
        const int N = nums.size();

        vector<int> delta(N + 1);
        for(int i = 0; i < k; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            delta[l] += val;
            delta[r + 1] -= val;
        }

        for(int i = 0; i < N; ++i){
            if(i >= 1){
                delta[i] += delta[i - 1];
            }
            if(delta[i] < nums[i]){
                return false;
            }
        }

        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();

        int l = 0;
        int r = Q;
        while(l != r){
            int mid = (l + r) / 2;
            if(isPossible(nums, queries, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        if(isPossible(nums, queries, r)){
            return r;
        }

        return -1;
    }
};