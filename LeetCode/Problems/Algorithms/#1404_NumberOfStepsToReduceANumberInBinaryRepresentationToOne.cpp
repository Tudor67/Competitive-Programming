class Solution {
public:
    int numSteps(string s) {
        const int N = s.length();
        
        int answer = 0;
        bool carry = 0;
        
        for(int i = N - 1; i >= 1; --i){
            if(s[i] == '0'){
                if(carry == 0){
                    answer += 1;
                }else{
                    answer += 2;
                }
            }
            
            if(s[i] == '1'){
                if(carry == 0){
                    answer += 2;
                    carry = 1;
                }else{
                    answer += 1;
                }
            }
        }
        
        answer += carry;
        
        return answer;
    }
};