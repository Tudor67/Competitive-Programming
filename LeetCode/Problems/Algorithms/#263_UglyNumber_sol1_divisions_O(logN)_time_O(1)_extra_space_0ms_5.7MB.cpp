class Solution {
public:
    bool isUgly(int n) {
        for(int prime: {2, 3, 5}){
            while(n >= 1 && n % prime == 0){
                n /= prime;
            }
        }
        return (n == 1);
    }
};