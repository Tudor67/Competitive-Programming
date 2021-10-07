class Solution {    
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int N = s.length();
        vector<bool> isPossible(N, false);
        isPossible[0] = (s[0] == '0');
        queue<int> reachablePositions;
        for(int i = 0; i <= N - 1; ++i){
            if(s[i] == '0'){
                int l = max(0, i - maxJump);
                int r = i - minJump;
                while(!reachablePositions.empty() && reachablePositions.front() < l){
                    reachablePositions.pop();
                }
                if(!reachablePositions.empty() && reachablePositions.front() <= r){
                    isPossible[i] = true;
                }
                if(isPossible[i]){
                    reachablePositions.push(i);
                }
            }
        }
        return isPossible[N - 1];
    }
};