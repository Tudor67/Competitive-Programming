class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int N = nums.size();
        
        deque<pair<int, int>> monoDQ;
        monoDQ.emplace_back(nums[0], 0);
        for(int i = 1; i < N; ++i){
            while(!monoDQ.empty() && i - monoDQ.front().second > k){
                monoDQ.pop_front();
            }
            int score = nums[i] + monoDQ.front().first;
            while(!monoDQ.empty() && monoDQ.back().first <= score){
                monoDQ.pop_back();
            }
            monoDQ.emplace_back(score, i);
        }
        
        return monoDQ.back().first;
    }
};