class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        deque<int> dq;
        for(int i = 0; i < nums.size(); ++i){
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            if(!dq.empty() && i - dq.front() + 1 > k){
                dq.pop_front();
            }
            dq.push_back(i);
            if(i >= k - 1){
                answer.push_back(nums[dq.front()]);
            }
        }
        return answer;
    }
};