class Solution {
public:
    int longestCycle(vector<int>& edges) {
        const int N = edges.size();

        vector<int> nextNodeFrom = edges;
        vector<int> inDegree(N);
        for(int node = 0; node < N; ++node){
            if(nextNodeFrom[node] != -1){
                inDegree[nextNodeFrom[node]] += 1;
            }
        }

        // Step 1: remove redundant paths going to a cycle or to a -1 node
        for(int srcNode = 0; srcNode < N; ++srcNode){
            int node = srcNode;
            while(node != -1 && inDegree[node] == 0){
                int nextNode = nextNodeFrom[node];
                nextNodeFrom[node] = -1;
                if(nextNode != -1){
                    inDegree[nextNode] -= 1;
                }
                node = nextNode;
            }
        }

        // Step 2: compute the size of the longest cycle
        int res = -1;
        for(int srcNode = 0; srcNode < N; ++srcNode){
            if(nextNodeFrom[srcNode] != -1){
                int cycleSize = -1;
                int node = srcNode;
                while(node != -1){
                    cycleSize += 1;
                    int nextNode = nextNodeFrom[node];
                    nextNodeFrom[node] = -1;
                    node = nextNode;
                }
                res = max(res, cycleSize);
            }
        }

        return res;
    }
};