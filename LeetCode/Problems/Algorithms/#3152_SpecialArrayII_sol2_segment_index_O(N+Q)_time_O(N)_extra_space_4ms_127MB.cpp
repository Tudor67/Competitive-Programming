class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();

        vector<int> segmentIndexOf(N);
        int segmentIndex = 0;
        for(int i = 0; i < N; ++i){
            if(i > 0 && (nums[i - 1] % 2) == (nums[i] % 2)){
                segmentIndex += 1;
            }
            segmentIndexOf[i] = segmentIndex;
        }

        vector<bool> res(Q);
        for(int i = 0; i < Q; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            res[i] = (segmentIndexOf[l] == segmentIndexOf[r]);
        }

        return res;
    }
};