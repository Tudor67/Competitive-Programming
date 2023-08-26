class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> res(N - k + 1);

        deque<int> dq;
        for(int i = 0; i < N; ++i){
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            if(!dq.empty() && dq.front() < i - k + 1){
                dq.pop_front();
            }
            dq.push_back(i);
            if(i >= k - 1){
                res[i - (k - 1)] = nums[dq.front()];
            }
        }

        return res;
    }
};