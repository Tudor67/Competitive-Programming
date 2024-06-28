class Solution {
private:
    bool isCenterNode(vector<vector<int>>& edges, int candidate){
        return (edges[0][0] == candidate || edges[0][1] == candidate) &&
               (edges[1][0] == candidate || edges[1][1] == candidate);
    }

public:
    int findCenter(vector<vector<int>>& edges) {
        if(isCenterNode(edges, edges[0][0])){
            return edges[0][0];
        }
        return edges[0][1];
    }
};