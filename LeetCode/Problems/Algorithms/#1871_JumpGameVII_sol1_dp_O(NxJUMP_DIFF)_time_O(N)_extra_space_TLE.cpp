class Solution {    
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int N = s.length();
        vector<bool> isPossible(N, false);
        isPossible[0] = (s[0] == '0');
        for(int i = 1; i <= N - 1; ++i){
            if(s[i] == '0'){
                for(int j = max(0, i - maxJump); j <= i - minJump; ++j){
                    if(isPossible[j]){
                        isPossible[i] = true;
                        break;
                    }
                }
            }
        }
        return isPossible[N - 1];
    }
};