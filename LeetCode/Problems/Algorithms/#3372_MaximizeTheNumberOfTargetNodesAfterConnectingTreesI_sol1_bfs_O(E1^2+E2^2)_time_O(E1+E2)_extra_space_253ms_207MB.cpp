class Solution {
private:
    using Tree = vector<vector<int>>;

    void createTree(vector<vector<int>>& edges, Tree& T){
        const int E = edges.size();
        const int N = E + 1;

        T.assign(N, {});
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            T[a].push_back(b);
            T[b].push_back(a);
        }
    }

    int computeGroupSize(int srcNode, const Tree& T, const int K){
        const int N = T.size();
        const int INF = 1e9;

        int groupSize = 0;
        vector<int> dist(N, INF);
        queue<int> q;
        dist[srcNode] = 0;
        q.push(srcNode);

        while(!q.empty() && dist[q.front()] <= K){
            int node = q.front();
            q.pop();

            groupSize += 1;

            for(int nextNode: T[node]){
                if(dist[nextNode] > dist[node] + 1){
                    dist[nextNode] = dist[node] + 1;
                    q.push(nextNode);
                }
            }
        }

        return groupSize;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        Tree T1;
        createTree(edges1, T1);

        Tree T2;
        createTree(edges2, T2);

        const int N1 = T1.size();
        vector<int> groupSizes1(N1);
        for(int node = 0; node < N1; ++node){
            groupSizes1[node] = computeGroupSize(node, T1, k);
        }

        const int N2 = T2.size();
        vector<int> groupSizes2(N2);
        for(int node = 0; node < N2; ++node){
            groupSizes2[node] = computeGroupSize(node, T2, k - 1);
        }

        int maxGroupSize2 = *max_element(groupSizes2.begin(), groupSizes2.end());

        vector<int> res = groupSizes1;
        for(int node = 0; node < N1; ++node){
            res[node] += maxGroupSize2;
        }

        return res;
    }
};