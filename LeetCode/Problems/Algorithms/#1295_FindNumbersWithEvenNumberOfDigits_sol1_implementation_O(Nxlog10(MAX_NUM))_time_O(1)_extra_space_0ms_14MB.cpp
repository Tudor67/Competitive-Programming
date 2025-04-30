class Solution {
private:
    int countDigits(int num){
        int digits = 1;
        while(num >= 10){
            digits += 1;
            num /= 10;
        }
        return digits;
    }

public:
    int findNumbers(vector<int>& nums) {
        const int N = nums.size();

        int validNums = 0;
        for(int num: nums){
            if(countDigits(num) % 2 == 0){
                validNums += 1;
            }
        }

        return validNums;
    }
};