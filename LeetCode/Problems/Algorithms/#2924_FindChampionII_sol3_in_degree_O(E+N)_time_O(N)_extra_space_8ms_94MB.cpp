class Solution {
public:
    int findChampion(int N, vector<vector<int>>& edges) {
        vector<int> inDegree(N);
        for(const vector<int>& EDGE: edges){
            inDegree[EDGE[1]] += 1;
        }

        if(count(inDegree.begin(), inDegree.end(), 0) == 1){
            return find(inDegree.begin(), inDegree.end(), 0) - inDegree.begin();
        }

        return -1;
    }
};