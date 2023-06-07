class Solution {
private:
    int computeMinTime(int node, vector<vector<int>>& childrenOf, vector<int>& informTime){
        if(childrenOf[node].empty()){
            return 0;
        }
        int childWorstTime = 0;
        for(int child: childrenOf[node]){
            childWorstTime = max(childWorstTime, computeMinTime(child, childrenOf, informTime));
        }
        return informTime[node] + childWorstTime;
    }

public:
    int numOfMinutes(int N, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> childrenOf(N);
        for(int node = 0; node < N; ++node){
            if(manager[node] != -1){
                childrenOf[manager[node]].push_back(node);
            }
        }

        return computeMinTime(headID, childrenOf, informTime);
    }
};