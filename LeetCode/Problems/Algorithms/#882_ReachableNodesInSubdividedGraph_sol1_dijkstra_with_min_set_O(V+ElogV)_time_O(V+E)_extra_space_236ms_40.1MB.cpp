class Solution {
private:
    using MinSet = set<pair<int, int>>;
    using Graph = vector<vector<pair<int, int>>>;
    using DistanceVector = vector<int>;
    const int INF = 2e9;
    
    void updateMinSet(MinSet& minSet, Graph& graph, DistanceVector& dist, int currentNode, int currentDist, const int& M){
        for(const pair<int, int>& P: graph[currentNode]){
            int nextNode = P.first;
            int intermNodes = P.second;
            int newDist = currentDist + intermNodes + 1;
            if(newDist <= M && newDist < dist[nextNode]){
                MinSet::iterator it = minSet.find({dist[nextNode], nextNode});
                if(it != minSet.end()){
                    minSet.erase(it);
                }
                dist[nextNode] = newDist;
                minSet.insert({dist[nextNode], nextNode});
            }
        }
    }
    
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        Graph graph(N);
        for(const vector<int>& EDGE: edges){
            graph[EDGE[0]].push_back({EDGE[1], EDGE[2]});
            graph[EDGE[1]].push_back({EDGE[0], EDGE[2]});
        }
        
        DistanceVector dist(N, INF);
        MinSet minSet;
        minSet.insert({0, 0});
        
        while(!minSet.empty()){
            int currentDist = minSet.begin()->first;
            int currentNode = minSet.begin()->second;
            minSet.erase(minSet.begin());
            dist[currentNode] = currentDist;
            updateMinSet(minSet, graph, dist, currentNode, currentDist, M);
        }
        
        int answer = 0;
        for(int node = 0; node < N; ++node){
            if(dist[node] <= M){
                answer += 1;
                for(const pair<int, int>& P: graph[node]){
                    int nextNode = P.first;
                    int intermNodes = P.second;
                    int nodeContrib = min(intermNodes, max(0, M - dist[node]));
                    int nextNodeContrib = min(intermNodes, max(0, M - dist[nextNode]));
                    if(nodeContrib + nextNodeContrib > intermNodes && nodeContrib > 0 && nextNodeContrib > 0){
                        nodeContrib = intermNodes / 2 + (node < nextNode) * (intermNodes % 2);
                    }
                    answer += nodeContrib;
                }
            }
        }
        
        return answer;
    }
};