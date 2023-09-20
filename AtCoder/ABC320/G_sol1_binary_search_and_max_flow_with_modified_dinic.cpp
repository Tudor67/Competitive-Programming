#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
    int from;
    int to;
    int capacity;
    int flow;

public:
    Edge(int from, int to, int capacity, int flow = 0):
         from(from), to(to), capacity(capacity), flow(flow){
    }

    int getRemainingCapacity() const{
        return capacity - flow;
    }
};

class Graph{
public:
    const int N;
    vector<Edge> edges;
    vector<vector<int>> edgeIndices;

public:
    Graph(const int& N): N(N){
        edgeIndices.resize(N);
    }

    void resetFlow(){
        for(Edge& e: edges){
            e.flow = 0;
        }
    }

    void addEdge(int from, int to, int c){
        edges.push_back(Edge(from, to, c));
        edges.push_back(Edge(to, from, 0));
        edgeIndices[from].push_back((int)edges.size() - 2);
        edgeIndices[to].push_back((int)edges.size() - 1);
    }
};

class Dinic{
private:
    Graph& G;
    const int N;
    const int SRC;
    const int DEST;
    const int MAX_VALID_NODE;
    const int INF = 1e8;
    vector<int> dist;
    vector<int> edgeStartIdx;
    queue<int> q;

    int bfs(){
        fill(dist.begin(), dist.end(), INF);
        
        while(!q.empty()){
            q.pop();
        }

        q.push(SRC);
        dist[SRC] = 0;

        while(!q.empty() && dist[DEST] == INF){
            int node = q.front();
            q.pop();

            for(int idx: G.edgeIndices[node]){
                Edge& edge = G.edges[idx];
                int nextNode = edge.to;
                if(nextNode <= MAX_VALID_NODE || nextNode == SRC || nextNode == DEST){
                    if(edge.getRemainingCapacity() > 0 && dist[nextNode] == INF){
                        dist[nextNode] = 1 + dist[node];
                        q.push(nextNode);
                    }
                }
            }
        }

        return (dist[DEST] != INF);
    }

    int dfs(int node, int minDelta){
        if(node == DEST){
            return minDelta;
        }
        for(; edgeStartIdx[node] < (int)G.edgeIndices[node].size(); ++edgeStartIdx[node]){
            int idx = G.edgeIndices[node][edgeStartIdx[node]];
            Edge& edge = G.edges[idx];
            Edge& edgeRev = G.edges[idx ^ 1];
            int nextNode = edge.to;
            if(edge.getRemainingCapacity() > 0 && dist[node] + 1 == dist[nextNode]){
                int delta = dfs(nextNode, min(minDelta, edge.getRemainingCapacity()));
                if(delta > 0){
                    edge.flow += delta;
                    edgeRev.flow -= delta;
                    return delta;
                }
            }
        }
        return 0;
    }

public:
    Dinic(Graph& G, const int& SRC, const int& DEST, const int& MAX_VALID_NODE):
          G(G), N(G.N), SRC(SRC), DEST(DEST), MAX_VALID_NODE(MAX_VALID_NODE){
    }

    int computeMaxFlow(){
        G.resetFlow();
        dist.resize(N);
        edgeStartIdx.resize(N);

        int maxFlow = 0;
        while(bfs()){
            fill(edgeStartIdx.begin(), edgeStartIdx.end(), 0);
            int delta = INF;
            while(delta > 0){
                delta = dfs(SRC, INF);
                maxFlow += delta;
            }
        }

        return maxFlow;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> s(N);
    for(int i = 0; i < N; ++i){
        cin >> s[i];
    }

    vector<vector<vector<int>>> pos(10, vector<vector<int>>(N));
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if((int)pos[s[i][j] - '0'][i].size() < N){
                pos[s[i][j] - '0'][i].push_back(j);
            }
        }
    }

    vector<bool> isPossible(10, true);
    for(char c = '0'; c <= '9'; ++c){
        for(int i = 0; i < N; ++i){
            if(pos[c - '0'][i].empty()){
                isPossible[c - '0'] = false;
            }else{
                int delta = pos[c - '0'][i].size();
                pos[c - '0'][i].resize(N);
                for(int j = delta; j < N; ++j){
                    pos[c - '0'][i][j] = pos[c - '0'][i][j - delta] + M;
                }
            }
        }
    }

    const int INF = N * M + 5;
    int res = INF;

    for(char targetChar = '0'; targetChar <= '9'; ++targetChar){
        if(!isPossible[targetChar - '0']){
            continue;
        }

        // Graph G for targetChar
        vector<int> times;
        times.reserve(N * N);
        for(int i = 0; i < N; ++i){
            for(int t: pos[targetChar - '0'][i]){
                times.push_back(t);
            }
        }

        sort(times.begin(), times.end());
        times.resize(unique(times.begin(), times.end()) - times.begin());

        const int T = times.size();
        const int SRC_NODE = N + T;
        const int DEST_NODE = N + T + 1;
        Graph G(N + T + 2);
        for(int i = 0; i < N; ++i){
            for(int t: pos[targetChar - '0'][i]){
                int timeNode = N + lower_bound(times.begin(), times.end(), t) - times.begin();
                G.addEdge(i, timeNode, 1);
                G.addEdge(timeNode, i, 1);
            }
        }

        for(int i = 0; i < N; ++i){
            G.addEdge(SRC_NODE, i, 1);
        }

        for(int i = N; i <= N + T - 1; ++i){
            G.addEdge(i, DEST_NODE, 1);
        }

        // binary search
        int l = 0;
        int r = INF;
        while(l != r){
            int mid = (l + r) / 2;
            int maxValidTimeNode = N + upper_bound(times.begin(), times.end(), mid) - times.begin() - 1;

            if(Dinic(G, SRC_NODE, DEST_NODE, maxValidTimeNode).computeMaxFlow() == N){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        res = min(res, r);
    }

    if(res == INF){
        res = -1;
    }

    cout << res;

    return 0;
}