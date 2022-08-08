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
        
        vector<pair<int, int>> maxNums(MAX_DIGITS_SUM + 1, {-1, -1});
        for(int num: nums){
            pair<int, int>& p = maxNums[computeDigitsSum(num)];
            if(num > p.first){
                p.second = p.first;
                p.first = num;
            }else if(num > p.second){
                p.second = num;
            }
        }
        
        int res = -1;
        for(int digitsSum = 1; digitsSum <= MAX_DIGITS_SUM; ++digitsSum){
            if(maxNums[digitsSum].second != -1){
                int max1 = maxNums[digitsSum].first;
                int max2 = maxNums[digitsSum].second;
                res = max(res, max1 + max2);
            }
        }
        
        return res;
    }
};