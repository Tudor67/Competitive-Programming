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
        const int MAX_DIGITS_SUM = 9 * 9;
        
        int res = -1;
        vector<int> maxNum(MAX_DIGITS_SUM + 1);
        for(int num: nums){
            int digitsSum = computeDigitsSum(num);
            if(maxNum[digitsSum] > 0){
                res = max(res, maxNum[digitsSum] + num);
            }
            maxNum[digitsSum] = max(maxNum[digitsSum], num);
        }
        
        return res;
    }
};