class Solution {
public:
    int myAtoi(string s) {
        const int N = s.length();
        
        // Step 1: remove leading whitespaces and save startPos of digits
        int startPos = 0;
        while(startPos < N && s[startPos] == ' '){
            startPos += 1;
        }
        
        // Step 2: extract sign and update startPos of digits
        int sign = 1;
        if(startPos < N){
            if(s[startPos] == '-'){
                sign = -1;
                startPos += 1;
            }else if(s[startPos] == '+'){
                sign = 1;
                startPos += 1;
            }
        }
        
        // Step 3: compute endPos of digits
        int endPos = startPos;
        while(endPos < N && isdigit(s[endPos])){
            endPos += 1;
        }
        
        // Step 4: build num from digits s[startPos .. endPos - 1]
        //         clamp the answer if sign * num is out of the 32-bit signed integer range
        int num = 0;
        int limit = INT_MAX;
        for(int i = startPos; i < endPos; ++i){
            if(num <= (limit - (s[i] - '0')) / 10){
                num = num * 10 + (s[i] - '0');
            }else{
                if(sign == -1){
                    return INT_MIN;
                }else{
                    return INT_MAX;
                }
            }
        }
        
        return sign * num;
    }
};