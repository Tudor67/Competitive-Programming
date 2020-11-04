class Solution {
private:
    using MinSet = set<pair<int, int>>;
    using Graph = vector<vector<pair<int, int>>>;
    const int INF = 1e9;
    
    void insertInSet(MinSet& minSet, Graph& graph, vector<int>& dist, const int& CURRENT_NODE, const int& CURRENT_DIST){
        for(const pair<int, int>& P: graph[CURRENT_NODE]){
            int nextNode = P.first;
            int weight = P.second;
            if(CURRENT_DIST + weight < dist[nextNode]){
                MinSet::iterator it = minSet.find({dist[nextNode], nextNode});
                if(it != minSet.end()){
                    minSet.erase(it);
                }
                dist[nextNode] = CURRENT_DIST + weight;
                minSet.insert({dist[nextNode], nextNode});
            }
        }
    }
    
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        Graph graph(N + 1);
        for(const vector<int>& t: times){
            int node = t[0];
            int nextNode = t[1];
            int weight = t[2];
            graph[node].push_back({nextNode, weight});
        }
        
        vector<int> dist(N + 1, INF);
        MinSet minSet;
        minSet.insert({0, K});
        
        while(!minSet.empty()){
            int currentDist = minSet.begin()->first;
            int currentNode = minSet.begin()->second;
            minSet.erase(minSet.begin());
            dist[currentNode] = currentDist;
            insertInSet(minSet, graph, dist, currentNode, currentDist);
        }
        
        int answer = *max_element(dist.begin() + 1, dist.end());
        if(answer == INF){
            answer = -1;
        }
        
        return answer;
    }
};