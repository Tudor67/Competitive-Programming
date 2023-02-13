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
    int differenceOfSum(vector<int>& nums) {
        const int N = nums.size();

        int numsSum = 0;
        int digitsSum = 0;
        for(int num: nums){
            numsSum += num;
            digitsSum += computeDigitsSum(num);
        }
        
        return numsSum - digitsSum;
    }
};