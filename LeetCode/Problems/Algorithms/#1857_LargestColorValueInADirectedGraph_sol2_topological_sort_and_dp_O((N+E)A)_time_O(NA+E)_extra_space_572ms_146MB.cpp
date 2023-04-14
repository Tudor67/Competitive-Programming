class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        const int N = colors.size();
        const int E = edges.size();
        const int A = 26;
        const int FIRST_COLOR = 'a';

        vector<vector<int>> G(N);
        vector<int> inDegree(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            inDegree[b] += 1;
        }

        queue<int> q;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 0){
                q.push(node);
            }
        }

        int res = 0;
        int processed = 0;
        vector<vector<int>> maxFreq(A, vector<int>(N));
        while(!q.empty()){
            int node = q.front();
            q.pop();

            processed += 1;
            maxFreq[colors[node] - FIRST_COLOR][node] += 1;

            res = max(res, maxFreq[colors[node] - FIRST_COLOR][node]);

            for(int nextNode: G[node]){
                for(char c = FIRST_COLOR; c < FIRST_COLOR + A; ++c){
                    maxFreq[c - FIRST_COLOR][nextNode] = max(maxFreq[c - FIRST_COLOR][nextNode],
                                                             maxFreq[c - FIRST_COLOR][node]);
                }
                inDegree[nextNode] -= 1;
                if(inDegree[nextNode] == 0){
                    q.push(nextNode);
                }
            }
        }

        if(processed < N){
            res = -1;
        }

        return res;
    }
};