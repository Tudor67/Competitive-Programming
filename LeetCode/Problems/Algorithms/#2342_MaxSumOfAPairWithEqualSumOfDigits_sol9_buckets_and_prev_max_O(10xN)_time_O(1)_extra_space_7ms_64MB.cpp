class Solution {
private:
    int computeDigitsSum(int num){
        int digitsSum = 0;
        while(num > 0){
            digitsSum += (num % 10);
            num /= 10;
        }
        return digitsSum;
    }

public:
    int maximumSum(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_DIGITS_SUM = 9 * 9;

        int maxSum = -1;
        vector<int> maxNumFor(MAX_DIGITS_SUM + 1, -1);

        for(int num: nums){
            int digitsSum = computeDigitsSum(num);
            if(maxNumFor[digitsSum] != -1){
                maxSum = max(maxSum, maxNumFor[digitsSum] + num);
            }
            maxNumFor[digitsSum] = max(maxNumFor[digitsSum], num);
        }
        
        return maxSum;
    }
};