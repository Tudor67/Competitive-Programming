class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> in_degree(N + 1, 0);
        vector<int> out_degree(N + 1, 0);
        for(const vector<int>& arc: trust){
            ++out_degree[arc[0]];
            ++in_degree[arc[1]];
        }
        
        int answer = -1;
        for(int node = 1; node <= N; ++node){
            if(in_degree[node] == N - 1 && out_degree[node] == 0){
                answer = node;
                break;
            }
        }
        return answer;
    }
};