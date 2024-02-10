class Solution {
private:
    int computeMaxDigit(int num){
        int maxDigit = 0;
        while(num > 0){
            maxDigit = max(maxDigit, num % 10);
            num /= 10;
        }
        return maxDigit;
    }

public:
    int maxSum(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> maxDigit(N);
        for(int i = 0; i < N; ++i){
            maxDigit[i] = computeMaxDigit(nums[i]);
        }

        int res = -1;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(maxDigit[i] == maxDigit[j]){
                    res = max(res, nums[i] + nums[j]);
                }
            }
        }
        
        return res;
    }
};