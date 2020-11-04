class Solution {
private:
    using MinHeap = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
    using Graph = vector<vector<pair<int, int>>>;
    const int INF = 1e9;
    
    void insertInHeap(MinHeap& minHeap, Graph& graph, const int& CURRENT_NODE, const int& CURRENT_DIST){
        for(const pair<int, int>& P: graph[CURRENT_NODE]){
            int nextNode = P.first;
            int weight = P.second;
            minHeap.push({CURRENT_DIST + weight, nextNode});
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
        MinHeap minHeap;
        minHeap.push({0, K});
        
        while(!minHeap.empty()){
            int currentDist = minHeap.top().first;
            int currentNode = minHeap.top().second;
            minHeap.pop();
            if(dist[currentNode] == INF){
                dist[currentNode] = currentDist;
                insertInHeap(minHeap, graph, currentNode, currentDist);
            }
        }
        
        int answer = *max_element(dist.begin() + 1, dist.end());
        if(answer == INF){
            answer = -1;
        }
        
        return answer;
    }
};