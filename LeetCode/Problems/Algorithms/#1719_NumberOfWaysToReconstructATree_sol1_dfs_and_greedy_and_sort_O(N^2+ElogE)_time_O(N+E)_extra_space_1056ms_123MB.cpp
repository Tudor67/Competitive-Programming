class Solution {
private:
    using Graph = vector<vector<int>>;

    bool contains(const vector<int>& A, const vector<int>& B){
        // return true if vector A (with unique elements)
        //             contains all elements of vector B (with unique elements)
        if(A.size() < B.size()){
            return false;
        }
        int indexB = 0;
        for(int indexA = 0; indexA < (int)A.size() && indexB < (int)B.size(); ++indexA){
            if(A[indexA] == B[indexB]){
                indexB += 1;
            }
        }
        return (indexB == (int)B.size());
    }

    void dfs(int node, unordered_set<int>& vis, Graph& G, bool& isValid, bool& containsDuplicateConfig){
        vis.insert(node);

        for(int nextNode: G[node]){
            if(vis.count(nextNode)){
                continue;
            }
            if(isValid && contains(G[node], G[nextNode])){
                containsDuplicateConfig = containsDuplicateConfig || (G[node].size() == G[nextNode].size());
                dfs(nextNode, vis, G, isValid, containsDuplicateConfig);
            }else{
                isValid = false;
                break;
            }
        }
    }

public:
    int checkWays(vector<vector<int>>& pairs) {
        int maxNode = 1;
        for(const vector<int>& P: pairs){
            int x = P[0];
            int y = P[1];
            maxNode = max(maxNode, max(x, y));
        }

        Graph G(maxNode + 1);
        int uniqueNodes = 0;
        for(const vector<int>& P: pairs){
            int x = P[0];
            int y = P[1];
            G[x].push_back(y);
            G[y].push_back(x);
            uniqueNodes += (int)((int)G[x].size() == 1);
            uniqueNodes += (int)((int)G[y].size() == 1);
        }

        int root = -1;
        for(int node = 1; node <= maxNode; ++node){
            G[node].push_back(node);
            if((int)G[node].size() == uniqueNodes){
                root = node;
            }
        }

        if(root == -1){
            return 0;
        }

        for(int node = 1; node <= maxNode; ++node){
            sort(G[node].begin(), G[node].end(),
                 [&](int lhs, int rhs){
                     return pair<int, int>{G[lhs].size(), lhs} >
                            pair<int, int>{G[rhs].size(), rhs};
                 });
        }

        unordered_set<int> vis;
        bool isValid = true;
        bool containsDuplicateConfig = false;
        dfs(root, vis, G, isValid, containsDuplicateConfig);

        if(!isValid){
            return 0;
        }

        if(!containsDuplicateConfig){
            return 1;
        }

        return 2;
    }
};