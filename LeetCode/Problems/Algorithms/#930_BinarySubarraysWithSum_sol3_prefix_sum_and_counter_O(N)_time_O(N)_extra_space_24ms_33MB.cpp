class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        const int N = nums.size();

        int res = 0;

        vector<int> freq(N + 1);
        freq[0] = 1;
        
        int prefSum = 0;
        for(int i = 0; i < N; ++i){
            prefSum += nums[i];
            if(prefSum - goal >= 0){
                res += freq[prefSum - goal];
            }
            freq[prefSum] += 1;
        }

        return res;
    }
};