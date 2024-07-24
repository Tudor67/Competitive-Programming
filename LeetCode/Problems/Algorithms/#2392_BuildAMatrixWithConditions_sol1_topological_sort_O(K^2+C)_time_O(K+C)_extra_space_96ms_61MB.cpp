class Solution {
private:
    vector<int> topologicalSort(int k, vector<vector<int>>& conditions){
        vector<vector<int>> G(k + 1);
        vector<int> inDegree(k + 1);
        for(const vector<int>& C: conditions){
            int a = C[0];
            int b = C[1];
            G[a].push_back(b);
            inDegree[b] += 1;
        }

        queue<int> q;
        for(int node = 1; node <= k; ++node){
            if(inDegree[node] == 0){
                q.push(node);
            }
        }

        vector<int> sortedValues;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            sortedValues.push_back(node);

            for(int nextNode: G[node]){
                inDegree[nextNode] -= 1;
                if(inDegree[nextNode] == 0){
                    q.push(nextNode);
                }
            }
        }

        if((int)sortedValues.size() == k){
            return sortedValues;
        }

        return {};
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> v = topologicalSort(k, rowConditions);
        vector<int> h = topologicalSort(k, colConditions);

        if(v.empty() || h.empty()){
            return {};
        }

        vector<int> rowOf(k + 1);
        vector<int> colOf(k + 1);
        for(int i = 0; i < k; ++i){
            rowOf[v[i]] = i;
            colOf[h[i]] = i;
        }

        vector<vector<int>> res(k, vector<int>(k));
        for(int val = 1; val <= k; ++val){
            res[rowOf[val]][colOf[val]] = val;
        }

        return res;
    }
};