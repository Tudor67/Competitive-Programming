class Solution {
private:
    bool isNoZeroInteger(int a){
        if(a <= 0){
            return false;
        }
        while(a > 9){
            if(a % 10 == 0){
                return false;
            }
            a /= 10;
        }
        return true;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        for(int a = 1; a <= n - 1; ++a){
            int b = n - a;
            if(isNoZeroInteger(a) && isNoZeroInteger(b)){
                return {a, b};
            }
        }
        return {0, 0};
    }
};