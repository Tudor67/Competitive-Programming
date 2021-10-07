class Solution {    
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int N = s.length();
        vector<bool> isPossible(N, false);
        isPossible[0] = (s[0] == '0');
        for(int i = 0, j = 0; i <= N - 1; ++i){
            if(s[i] == '0'){
                int l = max(0, i - maxJump);
                int r = i - minJump;
                while(j < N && (j < l || !isPossible[j])){
                    j += 1;
                }
                if(j <= r){
                    isPossible[i] = true;
                }
            }
        }
        return isPossible[N - 1];
    }
};