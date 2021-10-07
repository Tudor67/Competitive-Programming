class Solution {    
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int N = s.length();
        
        vector<bool> isPossible(N, false);
        isPossible[0] = (s[0] == '0');
        
        int status = 0;
        vector<int> d(N + 1, 0);
        for(int i = 0; i <= N - 1; ++i){
            status += d[i];
            if(s[i] == '0'){
                if(status >= 1){
                    isPossible[i] = true;
                }
                if(isPossible[i]){
                    int l = i + minJump;
                    int r = min(N - 1, i + maxJump);
                    if(l <= r){
                        d[l] += 1;
                        d[r + 1] -= 1;
                    }
                }
            }
        }
        
        return isPossible[N - 1];
    }
};