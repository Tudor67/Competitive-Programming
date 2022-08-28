class Solution {
private:
    vector<int> getDigitCount(int x){
        vector<int> digitCount(10);
        while(x > 0){
            digitCount[x % 10] += 1;
            x /= 10;
        }
        return digitCount;
    }
    
public:
    bool reorderedPowerOf2(int n) {
        const int MAX_NUM = 1e9;
        
        vector<int> nDigitCount = getDigitCount(n);
        for(int powOfTwo = 1; powOfTwo <= MAX_NUM; powOfTwo *= 2){
            if(nDigitCount == getDigitCount(powOfTwo)){
                return true;
            }
        }
        
        return false;
    }
};