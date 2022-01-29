class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int answer = nums[0];
        deque<pair<int, int>> mono;
        for(int i = 0; i < N; ++i){
            while(!mono.empty() && i - mono.front().second > k){
                mono.pop_front();
            }
            int maxSumAtI = nums[i];
            if(!mono.empty()){
                maxSumAtI += mono.front().first;
            }
            if(maxSumAtI > 0){
                while(!mono.empty() && mono.back().first <= maxSumAtI){
                    mono.pop_back();
                }
                mono.emplace_back(maxSumAtI, i);
            }
            answer = max(answer, maxSumAtI);
        }
        
        return answer;
    }
};