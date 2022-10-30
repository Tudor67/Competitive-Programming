class Solution {
private:
    using Graph = vector<vector<int>>;
    
    bool isPossible(const Graph& G, vector<int>& nums,
                    const int& TARGET_COMPONENT_SUM, const int& TARGET_COMPONENTS){
        const int N = G.size();
        
        vector<int> inDegree(N);
        for(int node = 0; node < N; ++node){
            for(int nextNode: G[node]){
                inDegree[nextNode] += 1;
            }
        }
        
        queue<int> q;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 1){
                q.push(node);
            }
        }
        
        vector<int> sumOf = nums;
        vector<bool> processed(N, false);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            processed[node] = true;
            
            for(int nextNode: G[node]){
                inDegree[nextNode] -= 1;
                if(!processed[nextNode] && sumOf[node] + sumOf[nextNode] <= TARGET_COMPONENT_SUM){
                    sumOf[nextNode] += sumOf[node];
                }
                if(inDegree[nextNode] == 1){
                    q.push(nextNode);
                }
            }
        }
        
        return (TARGET_COMPONENTS == count(sumOf.begin(), sumOf.end(), TARGET_COMPONENT_SUM));
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
        
        for(int componentSum = MAX_NUM; componentSum <= TOTAL_SUM; ++componentSum){
            if(TOTAL_SUM % componentSum == 0){
                int components = TOTAL_SUM / componentSum;
                if(isPossible(G, nums, componentSum, components)){
                    return components - 1;
                }
            }
        }
        
        return 0;
    }
};