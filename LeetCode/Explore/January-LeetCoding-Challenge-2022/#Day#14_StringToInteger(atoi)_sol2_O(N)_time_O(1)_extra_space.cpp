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
        //         if current num >= 2 ^ 31 - 1 then stop
        long long num = 0;
        long long limit = INT_MAX;
        for(int i = startPos; i < endPos && num < limit; ++i){
            num = num * 10 + (s[i] - '0');
        }
        
        // Step 5: clamp the answer if sign * num is out of the 32-bit signed integer range
        long long answer = sign * num;
        if(answer < (long long)INT_MIN){
            answer = INT_MIN;
        }else if(answer > (long long)INT_MAX){
            answer = INT_MAX;
        }
        
        return answer;
    }
};