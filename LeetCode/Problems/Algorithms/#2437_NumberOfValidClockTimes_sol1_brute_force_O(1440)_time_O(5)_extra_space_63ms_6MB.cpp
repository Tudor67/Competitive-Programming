class Solution {
public:
    int countTime(string targetTimeStr) {
        int validTimesCount = 0;
        
        for(int hh = 0; hh <= 23; ++hh){
            for(int mm = 0; mm <= 59; ++mm){
                string hhStr = (hh <= 9 ? "0" + to_string(hh) : to_string(hh));
                string mmStr = (mm <= 9 ? "0" + to_string(mm) : to_string(mm));
                string timeStr = hhStr + ":" + mmStr;
                
                bool isValid = true;
                for(int i = 0; i < 5; ++i){
                    if(targetTimeStr[i] != '?' && targetTimeStr[i] != ':' && targetTimeStr[i] != timeStr[i]){
                        isValid = false;
                    }
                }
                if(isValid){
                    validTimesCount += 1;
                }
            }
        }
        
        return validTimesCount;
    }
};