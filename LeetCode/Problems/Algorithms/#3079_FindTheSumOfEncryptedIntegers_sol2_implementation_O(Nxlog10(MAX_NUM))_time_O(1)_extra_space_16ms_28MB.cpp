class Solution {
private:
    int encrypt(int num){
        int maxDigit = 0;
        for(int x = num; x > 0; x /= 10){
            maxDigit = max(maxDigit, x % 10);
        }

        int res = 0;
        for(int x = num; x > 0; x /= 10){
            res = res * 10 + maxDigit;
        }

        return res;
    }

public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for(int num: nums){
            sum += encrypt(num);
        }
        return sum;
    }
};