class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int N = nums.size();
        vector<int> answer(N - k + 1);
        
        deque<int> dq;
        for(int i = 0; i < N; ++i){
            if(!dq.empty() && i - dq.front() + 1 > k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            if(i >= k - 1){
                answer[i - k + 1] = nums[dq.front()];
            }
        }
        
        return answer;
    }
};