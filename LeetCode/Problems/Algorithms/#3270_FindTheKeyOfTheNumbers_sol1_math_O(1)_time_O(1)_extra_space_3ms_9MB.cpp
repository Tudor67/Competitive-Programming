class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int key = 0;
        for(int p10 = 1; p10 <= 1000; p10 *= 10){
            int minDigit = min({num1 / p10 % 10,
                                num2 / p10 % 10,
                                num3 / p10 % 10});
            key += minDigit * p10;
        }
        return key;
    }
};