class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        const int N = nums.size();
        const int Q = queries.size();

        vector<int> xIndices;
        for(int i = 0; i < N; ++i){
            if(nums[i] == x){
                xIndices.push_back(i);
            }
        }

        vector<int> ans(Q);
        for(int i = 0; i < Q; ++i){
            if(queries[i] - 1 < (int)xIndices.size()){
                ans[i] = xIndices[queries[i] - 1];
            }else{
                ans[i] = -1;
            }
        }

        return ans;
    }
};