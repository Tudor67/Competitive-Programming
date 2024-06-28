class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();

        int niceSubarrays = 0;
        deque<int> dq;
        dq.push_back(-1);

        for(int i = 0; i < N; ++i){
            if(nums[i] % 2 == 1){
                dq.push_back(i);
            }
            if((int)dq.size() > k + 1){
                dq.pop_front();
            }
            if((int)dq.size() == k + 1){
                niceSubarrays += (dq[1] - dq[0]);
            }
        }

        return niceSubarrays;
    }
};