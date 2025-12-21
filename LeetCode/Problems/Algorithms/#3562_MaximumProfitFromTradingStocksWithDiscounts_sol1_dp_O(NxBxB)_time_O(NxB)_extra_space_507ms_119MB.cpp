class Solution {
private:
    using Graph = vector<vector<int>>;

    vector<int> merge(const vector<int>& A, const vector<int>& B, const int MAX_BUDGET){
        vector<int> C(MAX_BUDGET + 1);
        for(int i = 0; i < (int)A.size(); ++i){
            for(int j = 0; j < (int)B.size() && i + j <= MAX_BUDGET; ++j){
                C[i + j] = max(C[i + j], A[i] + B[j]);
            }
        }
        return C;
    }

    pair<vector<int>, vector<int>> f(int node, int budget,
                                     vector<int>& present, vector<int>& future, const Graph& G){
        vector<int> dp0Merged(budget + 1);
        vector<int> dp1Merged(budget + 1);

        for(int child: G[node]){
            auto [dp0Sub, dp1Sub] = f(child, budget, present, future, G);
            dp0Merged = merge(dp0Merged, dp0Sub, budget);
            dp1Merged = merge(dp1Merged, dp1Sub, budget);
        }

        // dp0[b]: max profit for budget b with no discount
        // dp1[b]: max profit for budget b with current node discounted
        // skip current node
        vector<int> dp0 = dp0Merged;
        vector<int> dp1 = dp0Merged;

        // take current node without discount
        int cost = present[node];
        int profit = future[node] - cost;
        for(int b = cost; b <= budget; ++b){
            dp0[b] = max(dp0[b], dp1Merged[b - cost] + profit);
        }

        // take current node with discount
        cost /= 2;
        profit = future[node] - cost;
        for(int b = cost; b <= budget; ++b){
            dp1[b] = max(dp1[b], dp1Merged[b - cost] + profit);
        }

        return {dp0, dp1};
    }

public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        Graph G(n);
        for(vector<int>& h: hierarchy){
            G[h[0] - 1].push_back(h[1] - 1);
        }
        return f(0, budget, present, future, G).first[budget];
    }
};