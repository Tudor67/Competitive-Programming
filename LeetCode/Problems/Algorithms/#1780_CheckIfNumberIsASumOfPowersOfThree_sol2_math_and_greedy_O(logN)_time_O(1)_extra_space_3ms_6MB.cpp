class Solution {
public:
    bool checkPowersOfThree(int n) {
        int p = 1;
        while(p * 3 <= n){
            p *= 3;
        }

        while(p >= 1 && n >= 1){
            if(p <= n){
                n -= p;
            }
            p /= 3;
        }

        return (n == 0);
    }
};