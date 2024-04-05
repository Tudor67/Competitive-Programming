class Solution {
public:
    int findChampion(int N, vector<vector<int>>& edges) {
        // Step 1: compute inDegree of each node
        vector<int> inDegree(N);
        for(const vector<int>& EDGE: edges){
            int b = EDGE[1];
            inDegree[b] += 1;
        }

        // Step 2: if we have at least two nodes with (inDegree == 0)
        //         it means that we have at least two champions => return -1
        int champions = count(inDegree.begin(), inDegree.end(), 0);
        if(champions >= 2){
            return -1;
        }
        
        // Step 3: find the node with (inDegree == 0) => that node is the champion
        return find(inDegree.begin(), inDegree.end(), 0) - inDegree.begin();
    }
};