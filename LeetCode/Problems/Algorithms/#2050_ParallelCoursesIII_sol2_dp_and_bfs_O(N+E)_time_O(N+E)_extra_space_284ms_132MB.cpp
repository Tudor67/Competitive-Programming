class Solution {
public:
    int minimumTime(int N, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> G(N);
        vector<int> inDegree(N);
        for(const vector<int>& R: relations){
            int a = R[0] - 1;
            int b = R[1] - 1;
            G[a].push_back(b);
            inDegree[b] += 1;
        }

        queue<int> q;
        vector<int> minValidTime(N);
        for(int node = 0; node < N; ++node){
            minValidTime[node] = time[node];
            if(inDegree[node] == 0){
                q.push(node);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nextNode: G[node]){
                inDegree[nextNode] -= 1;
                if(inDegree[nextNode] == 0){
                    q.push(nextNode);
                }
                minValidTime[nextNode] = max(minValidTime[nextNode], minValidTime[node] + time[nextNode]);
            }
        }

        return *max_element(minValidTime.begin(), minValidTime.end());
    }
};