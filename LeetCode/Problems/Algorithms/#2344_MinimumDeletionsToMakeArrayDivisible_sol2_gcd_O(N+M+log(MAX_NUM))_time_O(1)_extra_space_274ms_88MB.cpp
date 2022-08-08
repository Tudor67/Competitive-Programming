class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        const int N = nums.size();
        const int M = numsDivide.size();
        
        int numsDivideGCD = numsDivide[0];
        for(int num: numsDivide){
            numsDivideGCD = gcd(numsDivideGCD, num);
        }
        
        int minValidNum = -1;
        for(int num: nums){
            if(numsDivideGCD % num == 0){
                if(minValidNum == -1 || num < minValidNum){
                    minValidNum = num;
                }
            }
        }
        
        int res = -1;
        if(minValidNum != -1){
            res = 0;
            for(int num: nums){
                if(num < minValidNum){
                    res += 1;
                }
            }
        }
        
        return res;
    }
};