class Solution {
private:
    using Tree = vector<vector<int>>;

    void dfs(int level, int parent, int node, const Tree& T, vector<int>& parentOf, vector<int>& levelOf,
             vector<int>& nums, vector<int>& subtreeXOR){
        levelOf[node] = level;
        subtreeXOR[node] = nums[node];
        for(int nextNode: T[node]){
            if(nextNode != parent){
                dfs(level + 1, node, nextNode, T, parentOf, levelOf, nums, subtreeXOR);
                parentOf[nextNode] = node;
                subtreeXOR[node] ^= subtreeXOR[nextNode];
            }
        }
    }

    bool isAncestor(int a, int b, vector<vector<int>>& parentOf, vector<int>& levelOf){
        int diff = levelOf[b] - levelOf[a];
        for(int bit = 0; (1 << bit) <= diff; ++bit){
            if((diff >> bit) & 1){
                b = parentOf[bit][b];
            }
        }
        return (a == b);
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

        vector<vector<int>> parentOf(LOG_N + 1, vector<int>(N));
        vector<int> levelOf(N);
        vector<int> subtreeXOR(N);

        dfs(0, -1, 0, tree, parentOf[0], levelOf, nums, subtreeXOR);

        for(int k = 1; k <= LOG_N; ++k){
            for(int node = 0; node < N; ++node){
                parentOf[k][node] = parentOf[k - 1][parentOf[k - 1][node]];
            }
        }

        int minScore = *max_element(subtreeXOR.begin(), subtreeXOR.end());
        for(int i = 0; i < E; ++i){
            for(int j = i + 1; j < E; ++j){
                int a = (levelOf[edges[i][0]] > levelOf[edges[i][1]] ? edges[i][0] : edges[i][1]);
                int b = (levelOf[edges[j][0]] > levelOf[edges[j][1]] ? edges[j][0] : edges[j][1]);
                int aXOR = subtreeXOR[a];
                int bXOR = subtreeXOR[b];
                if(isAncestor(a, b, parentOf, levelOf)){
                    aXOR = subtreeXOR[a] ^ subtreeXOR[b];
                }else if(isAncestor(b, a, parentOf, levelOf)){
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