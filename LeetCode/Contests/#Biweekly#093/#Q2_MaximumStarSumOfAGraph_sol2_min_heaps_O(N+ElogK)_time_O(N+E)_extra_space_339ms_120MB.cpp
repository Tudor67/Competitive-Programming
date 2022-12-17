class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        const int N = vals.size();

        vector<priority_queue<int, vector<int>, greater<int>>> minHeap(N);
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            if(vals[b] > 0){
                minHeap[a].push(vals[b]);
            }
            if(vals[a] > 0){
                minHeap[b].push(vals[a]);
            }
            if((int)minHeap[a].size() > k){
                minHeap[a].pop();
            }
            if((int)minHeap[b].size() > k){
                minHeap[b].pop();
            }
        }
        
        int res = *max_element(vals.begin(), vals.end());
        for(int node = 0; node < N; ++node){
            int sum = vals[node];
            while(!minHeap[node].empty()){
                sum += minHeap[node].top();
                minHeap[node].pop();
            }
            res = max(res, sum);
        }
        
        return res;
    }
};