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
        
        int res = -1;
        vector<int> maxNumFor(10);
        for(int i = 0; i < N; ++i){
            int maxDigit = computeMaxDigit(nums[i]);
            if(maxNumFor[maxDigit]){
                res = max(res, maxNumFor[maxDigit] + nums[i]);
            }
            maxNumFor[maxDigit] = max(maxNumFor[maxDigit], nums[i]);
        }
        
        return res;
    }
};