class Solution {
private:
    void dfs(int node, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& vis){
        if(node >= 0 && !vis[node]){
            vis[node] = true;
            dfs(leftChild[node], leftChild, rightChild, vis);
            dfs(rightChild[node], leftChild, rightChild, vis);
        }
    }

public:
    bool validateBinaryTreeNodes(int N, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(N);
        for(int node = 0; node < N; ++node){
            if(leftChild[node] != -1){
                inDegree[leftChild[node]] += 1;
            }
            if(rightChild[node] != -1){
                inDegree[rightChild[node]] += 1;
            }
        }

        int rootCandidate = -1;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 0){
                rootCandidate = node;
            }
        }

        vector<bool> vis(N, false);
        dfs(rootCandidate, leftChild, rightChild, vis);

        return count(vis.begin(), vis.end(), true) == N &&
               *max_element(inDegree.begin(), inDegree.end()) <= 1;
    }
};