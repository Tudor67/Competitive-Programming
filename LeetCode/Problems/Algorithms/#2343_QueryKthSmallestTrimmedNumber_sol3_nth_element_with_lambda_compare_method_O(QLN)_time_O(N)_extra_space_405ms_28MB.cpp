class Solution {
private:
    int solve(vector<string>& nums, vector<int>& indices, int k, int trim){
        const int N = nums.size();
        
        auto comp = [&](const int& LHS, const int& RHS){
            const int L = nums[LHS].size();
            int stringCompareResult = nums[LHS].compare(L - trim, trim, nums[RHS], L - trim);
            return (stringCompareResult < 0 || (stringCompareResult == 0 && LHS < RHS));
        };
        
        nth_element(indices.begin(), indices.begin() + k - 1, indices.end(), comp);
        
        return indices[k - 1];
    }
    
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();
        
        vector<int> answer(Q);
        vector<int> indices(N);
        iota(indices.begin(), indices.end(), 0);
        for(int j = 0; j < Q; ++j){
            answer[j] = solve(nums, indices, queries[j][0], queries[j][1]);
        }
        
        return answer;
    }
};