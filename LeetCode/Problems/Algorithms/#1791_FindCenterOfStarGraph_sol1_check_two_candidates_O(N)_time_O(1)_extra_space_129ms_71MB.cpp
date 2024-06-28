class Solution {
private:
    bool isCenterNode(vector<vector<int>>& edges, int candidate){
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            if(a != candidate && b != candidate){
                return false;
            }
        }
        return true;
    }

public:
    int findCenter(vector<vector<int>>& edges) {
        if(isCenterNode(edges, edges[0][0])){
            return edges[0][0];
        }
        return edges[0][1];
    }
};