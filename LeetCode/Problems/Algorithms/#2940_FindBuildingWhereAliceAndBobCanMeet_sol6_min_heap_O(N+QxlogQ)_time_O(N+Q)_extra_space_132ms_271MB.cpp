class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        const int N = heights.size();
        const int Q = queries.size();

        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> minHeap;
        vector<vector<PII>> queriesAt(N);

        for(int queryIndex = 0; queryIndex < Q; ++queryIndex){
            int a = queries[queryIndex][0];
            int b = queries[queryIndex][1];

            if(a > b){
                swap(a, b);
            }

            int threshold = 1 + max(heights[a], heights[b]);
            if(a == b || heights[a] < heights[b]){
                threshold = heights[b];
            }

            queriesAt[b].push_back({threshold, queryIndex});
        }

        vector<int> res(Q, -1);
        for(int i = 0; i < N; ++i){
            for(PII p: queriesAt[i]){
                minHeap.push(p);
            }
            while(!minHeap.empty() && minHeap.top().first <= heights[i]){
                int queryIndex = minHeap.top().second;
                minHeap.pop();
                res[queryIndex] = i;
            }
        }

        return res;
    }
};