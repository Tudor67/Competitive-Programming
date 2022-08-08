class Solution {
private:
    int solve(vector<string>& nums, int k, int trim){
        const int N = nums.size();
        
        priority_queue<pair<string, int>> maxHeap;
        for(int i = 0; i < N; ++i){
            maxHeap.emplace(nums[i].substr(nums[i].length() - trim), i);
            if((int)maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        
        return maxHeap.top().second;
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