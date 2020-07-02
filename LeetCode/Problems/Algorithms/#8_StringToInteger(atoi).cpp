class Solution {
public:
    int myAtoi(string str) {
        str.push_back(' ');
        const int N = str.length();
        
        int pos = 0;
        while(pos < N && str[pos] == ' ') ++pos;
        
        long long answer = 0;
        if(pos == N || (!isdigit(str[pos]) && str[pos] != '-' && str[pos] != '+')){
            answer = 0;
        }
        else{
            int sign = 1;
            if(str[pos] == '-'){
                sign = -1;
            }
            
            int start_pos = pos + !isdigit(str[pos]);
            for(int i = start_pos; i < N; ++i){
                if(isdigit(str[i])){
                    answer = 10 * answer + str[i] - '0';
                }
                
                if(sign == 1 && answer >= INT_MAX){
                    answer = INT_MAX;
                    break;
                }
                if(sign == -1 && -answer <= INT_MIN){
                    answer = INT_MIN;
                    break;
                }
                if(!isdigit(str[i])){
                    answer = sign * answer;
                    break;
                }
            }
        }
        
        return (int)answer;
    }
};