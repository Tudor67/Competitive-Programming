class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        const int E = trust.size();
        
        vector<int> inDegree(N + 1);
        vector<int> outDegree(N + 1);
        for(const vector<int>& T: trust){
            int a = T[0];
            int b = T[1];
            outDegree[a] += 1;
            inDegree[b] += 1;
        }

        for(int i = 1; i <= N; ++i){
            if(inDegree[i] == N - 1 && outDegree[i] == 0){
                return i;
            }
        }

        return -1;
    }
};