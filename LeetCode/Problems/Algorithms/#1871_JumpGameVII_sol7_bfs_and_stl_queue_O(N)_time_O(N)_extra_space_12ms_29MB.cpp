class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int N = s.length();

        queue<int> validIndices;
        for(int i = 1; i < N; ++i){
            if(s[i] == '0'){
                validIndices.push(i);
            }
        }

        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int i = q.front();
            q.pop();

            if(i == N - 1){
                return true;
            }

            while(!validIndices.empty() && validIndices.front() < i + minJump){
                validIndices.pop();
            }

            while(!validIndices.empty() && validIndices.front() <= i + maxJump){
                q.push(validIndices.front());
                validIndices.pop();
            }
        }

        return false;
    }
};