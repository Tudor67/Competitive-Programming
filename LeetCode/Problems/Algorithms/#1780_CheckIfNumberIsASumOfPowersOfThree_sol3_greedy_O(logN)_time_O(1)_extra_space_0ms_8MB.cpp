class Solution {
public:
    bool checkPowersOfThree(int n) {
        int pow3 = 1;
        while(pow3 < n){
            pow3 *= 3;
        }

        while(n >= 1 && pow3 >= 1){
            if(n >= pow3){
                n -= pow3;
            }
            pow3 /= 3;
        }

        return (n == 0);
    }
};