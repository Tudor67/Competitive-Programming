class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if(tokens.empty()){
            return 0;
        }
        
        // Step 1: sort tokens
        sort(tokens.begin(), tokens.end());
        
        // Step 2: greedy solution
        // -> moving from left to right, apply 1st operation as long as you can;
        //    if it is not possible then apply one time 2nd operation (moving from right to left) and try again 1st operation;
        // -> update the answer at each step;
        const int N = tokens.size();
        int answer = 0;
        int power = P;
        int score = 0;
        int i = 0;
        int j = N - 1;
        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i];
                score += 1;
                i += 1;
            }else{
                if(score >= 1){
                    power += tokens[j];
                    score -= 1;
                    j -= 1;
                }else{
                    break;
                }
            }
            answer = max(score, answer);
        }
        
        return answer;
    }
};