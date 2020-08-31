class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int N = nums.size();
        vector<int> next_greater(N, -1);
        
        deque<int> dq;
        for(int i = 2 * N - 1; i >= 0; --i){
            while(!dq.empty() && nums[i % N] >= nums[dq.back() % N]){
                dq.pop_back();
            }
            if(!dq.empty() && nums[i % N] < nums[dq.back() % N]){
                next_greater[i % N] = nums[dq.back() % N];
            }
            dq.push_back(i);
        }
        
        return next_greater;
    }
};