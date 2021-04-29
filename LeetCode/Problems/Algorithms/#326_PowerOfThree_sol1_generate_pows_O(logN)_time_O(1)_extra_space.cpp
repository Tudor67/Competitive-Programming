class Solution {
public:
    bool isPowerOfThree(int n) {
        int p3 = 1;
        while(p3 <= n / 3){
            p3 *= 3;
        }
        return (p3 == n);
    }
};