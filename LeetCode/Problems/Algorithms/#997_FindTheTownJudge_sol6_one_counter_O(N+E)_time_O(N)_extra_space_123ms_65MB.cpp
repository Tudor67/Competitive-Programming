class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        const int E = trust.size();
        
        vector<int> balance(N + 1);
        for(const vector<int>& T: trust){
            int a = T[0];
            int b = T[1];
            balance[a] -= 1;
            balance[b] += 1;
        }

        for(int i = 1; i <= N; ++i){
            if(balance[i] == N - 1){
                return i;
            }
        }

        return -1;
    }
};