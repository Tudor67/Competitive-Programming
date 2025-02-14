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

        vector<int> firstMax(MAX_DIGITS_SUM + 1, -1);
        vector<int> secondMax(MAX_DIGITS_SUM + 1, -1);

        for(int num: nums){
            int digitsSum = computeDigitsSum(num);
            if(firstMax[digitsSum] < num){
                secondMax[digitsSum] = firstMax[digitsSum];
                firstMax[digitsSum] = num;
            }else if(secondMax[digitsSum] < num){
                secondMax[digitsSum] = num;
            }
        }

        int maxSum = -1;
        for(int digitsSum = 0; digitsSum <= MAX_DIGITS_SUM; ++digitsSum){
            if(secondMax[digitsSum] != -1){
                maxSum = max(maxSum, firstMax[digitsSum] + secondMax[digitsSum]);
            }
        }

        return maxSum;
    }
};