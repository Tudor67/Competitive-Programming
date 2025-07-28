class Solution {
private:
    using Tree = vector<vector<int>>;

    void dfs(int& t, int parent, int node, const Tree& T, vector<int>& nums, vector<int>& subtreeXOR,
             vector<int>& tin, vector<int>& tout){
        t += 1;
        tin[node] = t;
        subtreeXOR[node] = nums[node];
        for(int nextNode: T[node]){
            if(nextNode != parent){
                dfs(t, node, nextNode, T, nums, subtreeXOR, tin, tout);
                subtreeXOR[node] ^= subtreeXOR[nextNode];
            }
        }
        t += 1;
        tout[node] = t;
    }

    bool isAncestor(int a, int b, vector<int>& tin, vector<int>& tout){
        return (tin[a] < tin[b] && tin[b] < tout[a]);
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        const int N = nums.size();
        const int E = N - 1;
        const int LOG_N = log2(N);

        Tree tree(N);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        vector<int> subtreeXOR(N);
        vector<int> tin(N);
        vector<int> tout(N);

        int t = 0;
        dfs(t, -1, 0, tree, nums, subtreeXOR, tin, tout);

        int minScore = *max_element(subtreeXOR.begin(), subtreeXOR.end());
        for(int i = 0; i < E; ++i){
            for(int j = i + 1; j < E; ++j){
                int a = (tin[edges[i][0]] > tin[edges[i][1]] ? edges[i][0] : edges[i][1]);
                int b = (tin[edges[j][0]] > tin[edges[j][1]] ? edges[j][0] : edges[j][1]);
                int aXOR = subtreeXOR[a];
                int bXOR = subtreeXOR[b];
                if(isAncestor(a, b, tin, tout)){
                    aXOR = subtreeXOR[a] ^ subtreeXOR[b];
                }else if(isAncestor(b, a, tin, tout)){
                    bXOR = subtreeXOR[b] ^ subtreeXOR[a];
                }
                int cXOR = subtreeXOR[0] ^ aXOR ^ bXOR;
                int score = max({aXOR, bXOR, cXOR}) - min({aXOR, bXOR, cXOR});
                minScore = min(minScore, score);
            }
        }

        return minScore;
    }
};