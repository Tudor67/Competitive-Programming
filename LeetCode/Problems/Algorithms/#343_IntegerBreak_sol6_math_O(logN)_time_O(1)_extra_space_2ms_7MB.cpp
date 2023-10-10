class Solution {
public:
    int integerBreak(int N) {
        if(N <= 3){
            return N - 1;
        }

        if(N % 3 == 0){
            return pow(3, N / 3);
        }

        if(N % 3 == 1){
            return pow(3, N / 3 - 1) * 4;
        }

        return pow(3, N / 3) * 2;
    }
};