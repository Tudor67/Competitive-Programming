class Solution {
private:
    int computeReverseNumber(int num){
        int revNum = 0;
        while(num > 0){
            revNum = revNum * 10 + (num % 10);
            num /= 10;
        }
        return revNum;
    }
    
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; ++i){
            if(i + computeReverseNumber(i) == num){
                return true;
            }
        }
        return false;
    }
};