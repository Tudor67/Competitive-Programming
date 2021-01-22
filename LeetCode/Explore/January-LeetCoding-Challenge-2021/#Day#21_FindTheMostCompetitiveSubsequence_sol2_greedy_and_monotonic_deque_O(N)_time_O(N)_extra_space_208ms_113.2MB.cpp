class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        const int N = nums.size();
        vector<int> answer;
        deque<int> dq;
        for(int i = 0; i < N; ++i){
            while(!dq.empty() && nums[dq.back()] > nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= N - k){
                answer.push_back(nums[dq.front()]);
                dq.pop_front();
            }
        }
        return answer;
    }
};