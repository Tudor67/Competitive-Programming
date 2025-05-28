class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        const int N = colors.length();
        const int E = edges.size();
        const int A = 26;

        vector<vector<int>> G(N);
        vector<int> inDegree(N);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            G[a].push_back(b);
            inDegree[b] += 1;
        }

        queue<int> q;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 0){
                q.push(node);
            }
        }

        vector<vector<int>> maxFreqOfColor(A, vector<int>(N));
        while(!q.empty()){
            int node = q.front();
            q.pop();

            maxFreqOfColor[colors[node] - 'a'][node] += 1;

            for(int nextNode: G[node]){
                inDegree[nextNode] -= 1;
                if(inDegree[nextNode] == 0){
                    q.push(nextNode);
                }
                for(char c = 'a'; c <= 'z'; ++c){
                    maxFreqOfColor[c - 'a'][nextNode] = max(maxFreqOfColor[c - 'a'][nextNode],
                                                            maxFreqOfColor[c - 'a'][node]);
                }
            }
        }

        bool containsCycle = false;
        int maxColorValue = 0;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] != 0){
                containsCycle = true;
            }
            for(char c = 'a'; c <= 'z'; ++c){
                maxColorValue = max(maxColorValue, maxFreqOfColor[c - 'a'][node]);
            }
        }

        if(containsCycle){
            maxColorValue = -1;
        }

        return maxColorValue;
    }
};