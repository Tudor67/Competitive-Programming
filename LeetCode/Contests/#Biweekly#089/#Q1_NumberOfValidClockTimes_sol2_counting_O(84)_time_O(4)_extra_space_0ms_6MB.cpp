class Solution {
private:
    int validXCount(int firstVal, int lastVal, string& targetStr){
        int validCount = 0;
        
        for(int val = firstVal; val <= lastVal; ++val){
            string str = (val <= 9 ? "0" + to_string(val) : to_string(val));
            
            bool isValid = true;
            for(int i = 0; i < 2; ++i){
                if(targetStr[i] != '?' && targetStr[i] != str[i]){
                    isValid = false;
                }
            }
            if(isValid){
                validCount += 1;
            }
        }
        
        return validCount;
    }
    
public:
    int countTime(string targetTimeStr) {
        string targetHHStr = targetTimeStr.substr(0, 2);
        string targetMMStr = targetTimeStr.substr(3);
        
        int validHHCount = validXCount(0, 23, targetHHStr);
        int validMMCount = validXCount(0, 59, targetMMStr);
        
        return validHHCount * validMMCount;
    }
};