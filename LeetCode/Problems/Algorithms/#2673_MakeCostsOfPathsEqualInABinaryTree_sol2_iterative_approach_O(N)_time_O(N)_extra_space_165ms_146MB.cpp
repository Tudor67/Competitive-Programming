class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        vector<int> pathSum(n);
        pathSum[0] = cost[0];
        for(int i = 1; i < n; ++i){
            pathSum[i] = cost[i] + pathSum[(i - 1) / 2];
        }
        
        int maxPathSum = *max_element(pathSum.begin(), pathSum.end());
        vector<int> a(n);

        for(int node = n - 1; node >= 0; --node){
            if(2 * node + 2 >= n){
                // leaf node
                a[node] = maxPathSum - pathSum[node];
            }else{
                int commonSum = min(a[2 * node + 1], a[2 * node + 2]);
                a[node] = commonSum;
                a[2 * node + 1] -= commonSum;
                a[2 * node + 2] -= commonSum;
            }
        }
        
        return accumulate(a.begin(), a.end(), 0);
    }
};