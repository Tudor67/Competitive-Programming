class Solution {
private:
    int solve(vector<string>& nums, int k, int trim){
        const int N = nums.size();
        
        auto comp = [&](const int& LHS, const int& RHS){
            const int L = nums[LHS].size();
            int stringCompareResult = nums[LHS].compare(L - trim, trim, nums[RHS], L - trim);
            return (stringCompareResult < 0 || (stringCompareResult == 0 && LHS < RHS));
        };
        
        priority_queue<int, vector<int>, decltype(comp)> maxHeap(comp);
        for(int i = 0; i < N; ++i){
            maxHeap.push(i);
            if((int)maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        
        return maxHeap.top();
    }
    
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();
        
        vector<int> answer(Q);
        for(int j = 0; j < Q; ++j){
            answer[j] = solve(nums, queries[j][0], queries[j][1]);
        }
        
        return answer;
    }
};