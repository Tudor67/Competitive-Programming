class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int level, int parentNode, int node, vector<int>& nodeOf, vector<int>& levelOf,
             vector<int>& nums, const Graph& G, vector<vector<int>>& coprimesFor, vector<int>& res){
        levelOf[node] = level;

        for(int num: coprimesFor[nums[node]]){
            if(nodeOf[num] >= 0){
                if(res[node] == -1 || levelOf[nodeOf[num]] > levelOf[res[node]]){
                    res[node] = nodeOf[num];
                }
            }
        }

        int temp = nodeOf[nums[node]];
        nodeOf[nums[node]] = node;
        for(int child: G[node]){
            if(child != parentNode){
                dfs(level + 1, node, child, nodeOf, levelOf, nums, G, coprimesFor, res);
            }
        }
        nodeOf[nums[node]] = temp;
    }

public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        Graph G(N);
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<vector<int>> coprimesFor(MAX_NUM + 1);
        for(int num1 = 1; num1 <= MAX_NUM; ++num1){
            for(int num2 = 1; num2 <= MAX_NUM; ++num2){
                if(gcd(num1, num2) == 1){
                    coprimesFor[num1].push_back(num2);
                }
            }
        }

        vector<int> nodeOf(MAX_NUM + 1, -1);
        vector<int> levelOf(N, 0);
        vector<int> res(N, -1);
        dfs(0, -1, 0, nodeOf, levelOf, nums, G, coprimesFor, res);

        return res;
    }
};