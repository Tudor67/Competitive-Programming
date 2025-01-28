class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        const int N = favorite.size();

        vector<int> inDegree(N);
        for(int node = 0; node < N; ++node){
            inDegree[favorite[node]] += 1;
        }

        queue<int> q;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 0){
                q.push(node);
            }
        }

        vector<int> maxLen(N, 1);
        vector<bool> vis(N, false);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            vis[node] = true;

            int nextNode = favorite[node];
            maxLen[nextNode] = max(maxLen[nextNode], maxLen[node] + 1);
            inDegree[nextNode] -= 1;
            if(inDegree[nextNode] == 0){
                q.push(nextNode);
            }
        }

        int res2 = 0;
        int res3 = 0;
        for(int startNode = 0; startNode < N; ++startNode){
            if(!vis[startNode]){
                vis[startNode] = true;
                int cycleSize = 1;
                int node = favorite[startNode];
                while(!vis[node]){
                    cycleSize += 1;
                    vis[node] = true;
                    node = favorite[node];
                }

                if(cycleSize == 2){
                    res2 += (maxLen[startNode] + maxLen[favorite[startNode]]);
                }else{
                    res3 = max(res3, cycleSize);
                }
            }
        }

        return max(res2, res3);
    }
};