class Solution {
private:
    bool isPowerOfTwo(int x){
        return ((x - 1) & x) == 0;
    }
    
public:
    bool isReachable(int targetX, int targetY) {
        return isPowerOfTwo(gcd(targetX, targetY));
    }
};