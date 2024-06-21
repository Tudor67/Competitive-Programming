class Solution {
public:
    bool judgeSquareSum(int c) {
        unsigned int b = floor(sqrt(c)) + 1;
        for(unsigned int a = 0; a * a <= c; ++a){
            while(a * a + b * b > c){
                b -= 1;
            }
            if(a * a + b * b == c){
                return true;
            }
        }
        return false;
    }
};