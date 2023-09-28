class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int node, const Graph& G, vector<int>& maxLen){
        if(maxLen[node] > 0){
            return;
        }
        maxLen[node] = 1;
        for(int nextNode: G[node]){
            dfs(nextNode, G, maxLen);
            maxLen[node] = max(maxLen[node], maxLen[nextNode] + 1);
        }
    }

public:
    int longestStrChain(vector<string>& words) {
        const int W = words.size();

        unordered_map<string, int> wordToNode;
        for(int i = 0; i < W; ++i){
            wordToNode[words[i]] = i;
        }

        Graph G(W);
        for(int i = 0; i < W; ++i){
            const int L = words[i].length();
            for(int j = 0; j < L; ++j){
                string predecessor = words[i].substr(0, j) + words[i].substr(j + 1);
                if(wordToNode.count(predecessor)){
                    G[wordToNode[predecessor]].push_back(i);
                }
            }
        }

        vector<int> maxLen(W);
        for(int node = 0; node < W; ++node){
            dfs(node, G, maxLen);
        }

        return *max_element(maxLen.begin(), maxLen.end());
    }
};