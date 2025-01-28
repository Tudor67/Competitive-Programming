class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        const int N = numCourses;
        const int Q = queries.size();

        vector<vector<bool>> needs(N, vector<bool>(N, false));
        for(const vector<int>& P: prerequisites){
            int a = P[0];
            int b = P[1];
            needs[b][a] = true;
        }

        for(int k = 0; k < N; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    needs[i][j] = needs[i][j] || (needs[i][k] && needs[k][j]);
                }
            }
        }

        vector<bool> res(Q);
        for(int i = 0; i < Q; ++i){
            res[i] = needs[queries[i][1]][queries[i][0]];
        }

        return res;
    }
};