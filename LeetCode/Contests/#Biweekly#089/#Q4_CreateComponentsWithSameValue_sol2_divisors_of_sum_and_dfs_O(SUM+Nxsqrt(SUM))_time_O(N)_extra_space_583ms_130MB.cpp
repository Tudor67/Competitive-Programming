class Solution {
private:
    using Graph = vector<vector<int>>;
    
    void dfs(int parentNode, int node, vector<int>& sumOf, const Graph& G, const int& TARGET_COMPONENT_SUM){
        for(int child: G[node]){
            if(child != parentNode){
                dfs(node, child, sumOf, G, TARGET_COMPONENT_SUM);
                if(sumOf[node] + sumOf[child] <= TARGET_COMPONENT_SUM){
                    sumOf[node] += sumOf[child];
                }
            }
        }
    }
    
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        
        Graph G(N);
        for(const vector<int>& E: edges){
            int x = E[0];
            int y = E[1];
            G[x].push_back(y);
            G[y].push_back(x);
        }
        
        vector<int> sumOf(N);
        for(int componentSum = MAX_NUM; componentSum <= TOTAL_SUM; ++componentSum){
            if(TOTAL_SUM % componentSum == 0){
                int components = TOTAL_SUM / componentSum;
                
                copy(nums.begin(), nums.end(), sumOf.begin());
                dfs(0, 0, sumOf, G, componentSum);
                
                if(components == count(sumOf.begin(), sumOf.end(), componentSum)){
                    return components - 1;
                }
            }
        }
        
        return 0;
    }
};