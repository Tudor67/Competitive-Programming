class Solution {
private:
    using Graph = vector<vector<int>>;

    bool isPredecessor(string& A, string& B){
        const int A_LEN = A.length();
        const int B_LEN = B.length();

        if(A_LEN + 1 != B_LEN){
            return false;
        }

        int bIndex = 0;
        for(char c: A){
            while(bIndex < B_LEN && c != B[bIndex]){
                bIndex += 1;
            }
            if(bIndex == B_LEN){
                return false;
            }
            bIndex += 1;
        }

        return true;
    }

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

        Graph G(W);
        for(int i = 0; i < W; ++i){
            for(int j = 0; j < W; ++j){
                if(isPredecessor(words[i], words[j])){
                    G[i].push_back(j);
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