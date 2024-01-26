class Solution {
public:
    bool isGood(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        if(MAX_NUM >= N){
            return false;
        }

        vector<int> freq(N);
        for(int num: nums){
            freq[num] += 1;
        }

        for(int num = 1; num <= N - 2; ++num){
            if(freq[num] != 1){
                return false;
            }
        }

        return (freq[N - 1] == 2);
    }
};