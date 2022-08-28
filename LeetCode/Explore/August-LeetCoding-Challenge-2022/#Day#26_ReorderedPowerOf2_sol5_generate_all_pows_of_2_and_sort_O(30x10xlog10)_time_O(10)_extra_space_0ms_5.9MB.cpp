class Solution {
public:
    bool reorderedPowerOf2(int n) {
        const int MAX_NUM = 1e9;
        
        string sortedNStr = to_string(n);
        sort(sortedNStr.begin(), sortedNStr.end());
        
        for(int powOfTwo = 1; powOfTwo <= MAX_NUM; powOfTwo *= 2){
            string sortedPowOfTwoStr = to_string(powOfTwo);
            sort(sortedPowOfTwoStr.begin(), sortedPowOfTwoStr.end());
            if(sortedNStr == sortedPowOfTwoStr){
                return true;
            }
        }
        
        return false;
    }
};