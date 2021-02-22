#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
using Graph = vector<vector<PII>>;
using MinHeap = priority_queue<PII, vector<PII>, greater<PII>>;

const int INF = INT_MAX;
const int W = 51;

void addArcs(Graph& g, int x, int y, int c){
    g[x * W].push_back({y * W + c, 0});
    for(int i = 1; i <= W - 1; ++ i){
        g[x * W + i].push_back({y * W, (i + c) * (i + c)});
    }
}

void solve(istream& cin, ostream& cout){
    int N, M;
    cin >> N >> M;

    Graph g(N * W);
    for(int i = 0; i < M; ++i){
        int x, y, c;
        cin >> x >> y >> c;
        --x;
        --y;
        addArcs(g, x, y, c);
        addArcs(g, y, x, c);
    }

    MinHeap minHeap;
    vector<int> minCost(N * W, INF);
    minHeap.push({0, 0});
    minCost[0] = 0;
    
    while(!minHeap.empty()){
        int node = minHeap.top().second;
        minHeap.pop();

        for(const pair<int, int>& P: g[node]){
            int nextNode = P.first;
            int costToNextNode = P.second;
            if(minCost[node] + costToNextNode < minCost[nextNode]){
                minCost[nextNode] = minCost[node] + costToNextNode;
                minHeap.push({minCost[nextNode], nextNode});
            }
        }
    }

    for(int node = 0; node < N; ++node){
        if(minCost[node * W] == INF){
            minCost[node * W] = -1;
        }
        cout << minCost[node * W] << " ";
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve(cin, cout);

    return 0;
}