class Solution {
private:
    void dfs(int node, vector<int>& pathSum, vector<int>& a, int maxPathSum){
        if(2 * node + 2 >= (int)pathSum.size()){
            // leaf node
            a[node] = maxPathSum - pathSum[node];
        }else{
            dfs(2 * node + 1, pathSum, a, maxPathSum);
            dfs(2 * node + 2, pathSum, a, maxPathSum);
            
            int commonSum = min(a[2 * node + 1], a[2 * node + 2]);
            a[node] = commonSum;
            a[2 * node + 1] -= commonSum;
            a[2 * node + 2] -= commonSum;
        }
    }
    
public:
    int minIncrements(int n, vector<int>& cost) {
        vector<int> pathSum(n);
        pathSum[0] = cost[0];
        for(int i = 1; i < n; ++i){
            pathSum[i] = cost[i] + pathSum[(i - 1) / 2];
        }
        
        vector<int> a(n);
        int maxPathSum = *max_element(pathSum.begin(), pathSum.end());
        dfs(0, pathSum, a, maxPathSum);
        
        return accumulate(a.begin(), a.end(), 0);
    }
};