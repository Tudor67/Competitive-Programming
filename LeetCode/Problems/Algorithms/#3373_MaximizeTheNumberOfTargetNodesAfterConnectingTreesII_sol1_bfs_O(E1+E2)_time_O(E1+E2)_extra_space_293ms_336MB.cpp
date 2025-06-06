class Solution {
private:
    vector<int> createTreeAndComputeDistancesFromFirstNode(vector<vector<int>>& edges){
        const int E = edges.size();
        const int N = E + 1;
        const int INF = 1e9;

        vector<vector<int>> T(N);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            T[a].push_back(b);
            T[b].push_back(a);
        }

        vector<int> dist(N, INF);
        queue<int> q;
        dist[0] = 0;
        q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nextNode: T[node]){
                if(dist[nextNode] > dist[node] + 1){
                    dist[nextNode] = dist[node] + 1;
                    q.push(nextNode);
                }
            }
        }

        return dist;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> dist1 = createTreeAndComputeDistancesFromFirstNode(edges1);
        vector<int> dist2 = createTreeAndComputeDistancesFromFirstNode(edges2);

        const int N1 = dist1.size();
        const int N2 = dist2.size();
        const int EVEN1 = count_if(dist1.begin(), dist1.end(), [](int d){ return (d % 2 == 0); });
        const int ODD1 = N1 - EVEN1;
        const int EVEN2 = count_if(dist2.begin(), dist2.end(), [](int d){ return (d % 2 == 0); });
        const int ODD2 = N2 - EVEN2;

        vector<int> res(N1);
        for(int node = 0; node < N1; ++node){
            if(dist1[node] % 2 == 0){
                res[node] = EVEN1 + max(EVEN2, ODD2);
            }else{
                res[node] = ODD1 + max(EVEN2, ODD2);
            }
        }

        return res;
    }
};