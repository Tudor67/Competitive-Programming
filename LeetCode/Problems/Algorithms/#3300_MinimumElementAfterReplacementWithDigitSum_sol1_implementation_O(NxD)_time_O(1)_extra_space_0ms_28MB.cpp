class Solution {
public:
    int minElement(vector<int>& nums) {
        int minDigitsSum = INT_MAX;
        for(int num: nums){
            int digitsSum = 0;
            while(num > 0){
                digitsSum += num % 10;
                num /= 10;
            }
            minDigitsSum = min(minDigitsSum, digitsSum);
        }
        return minDigitsSum;
    }
};