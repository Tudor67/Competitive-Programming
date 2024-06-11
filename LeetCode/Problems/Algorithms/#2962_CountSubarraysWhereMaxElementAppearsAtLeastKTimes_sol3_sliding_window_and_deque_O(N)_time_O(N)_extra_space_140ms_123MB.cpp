class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        long long res = 0;
        deque<int> dq;
        for(int i = 0; i < N; ++i){
            if(nums[i] == MAX_NUM){
                dq.push_back(i);
            }
            if((int)dq.size() > k){
                dq.pop_front();
            }
            if((int)dq.size() == k){
                res += (dq.front() + 1);
            }
        }

        return res;
    }
};