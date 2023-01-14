class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int parentNode, int node, string& s, const Graph& G, vector<int>& maxLen, int& res){
        int firstMaxLen = 0;
        int secondMaxLen = 0;
        for(int child: G[node]){
            if(child != parentNode){
                dfs(node, child, s, G, maxLen, res);
                if(s[node] != s[child]){
                    if(maxLen[child] >= firstMaxLen){
                        secondMaxLen = firstMaxLen;
                        firstMaxLen = maxLen[child];
                    }else if(maxLen[child] >= secondMaxLen){
                        secondMaxLen = maxLen[child];
                    }
                }
            }
        }
        maxLen[node] = firstMaxLen + 1;
        res = max(res, firstMaxLen + 1 + secondMaxLen);
    }

public:
    int longestPath(vector<int>& parent, string s) {
        const int N = s.length();

        Graph G(N);
        for(int node = 1; node < N; ++node){
            G[node].push_back(parent[node]);
            G[parent[node]].push_back(node);
        }

        // maxLen[node]: max len of a valid path ending at node
        //               (path ending with char s[node])
        vector<int> maxLen(N);
        int res = 0;
        dfs(-1, 0, s, G, maxLen, res);

        return res;
    }
};