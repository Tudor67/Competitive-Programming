class Solution {
public:
    string convert(string s, int numRows) {
        const int N = s.length();
        string answer;
        
        if(numRows == 1){
            answer = s;
        }else{
            for(int step = 0; step < min(numRows, N); ++step){
                int step_len1 = 2 * (numRows - 1) - 2 * step;
                int step_len2 = 2 * step;

                answer += s[step];
                for(int i = step; i < N; i += step_len1 + step_len2){
                    if(step_len1 > 0 && i + step_len1 < N){
                        answer += s[i + step_len1];
                    }
                    if(step_len2 > 0 && i + step_len1 + step_len2 < N){
                        answer += s[i + step_len1 + step_len2];
                    }
                }   
            }
        }
        
        return answer;
    }
};