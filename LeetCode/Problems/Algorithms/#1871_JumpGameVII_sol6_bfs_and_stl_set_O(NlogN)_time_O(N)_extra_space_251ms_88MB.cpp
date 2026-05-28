class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int N = s.length();

        set<int> validIndices;
        for(int i = 1; i < N; ++i){
            if(s[i] == '0'){
                validIndices.insert(i);
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

            auto it = validIndices.lower_bound(i + minJump);
            while(it != validIndices.end() && *it - i <= maxJump){
                q.push(*it);
                it = validIndices.erase(it);
            }
        }

        return false;
    }
};