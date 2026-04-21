class Solution {
private:
    int reverse(int num){
        int reversedNum = 0;
        while(num > 0){
            reversedNum = reversedNum * 10 + num % 10;
            num /= 10;
        }
        return reversedNum;
    }

public:
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};