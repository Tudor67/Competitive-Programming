class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        const int N = nums.size();
        const int M = numsDivide.size();
        
        int numsDivideGCD = numsDivide[0];
        for(int num: numsDivide){
            numsDivideGCD = gcd(numsDivideGCD, num);
        }
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        for(int i = 0; i < N; ++i){
            if(numsDivideGCD % sortedNums[i] == 0){
                return i;
            }
        }
        
        return -1;
    }
};