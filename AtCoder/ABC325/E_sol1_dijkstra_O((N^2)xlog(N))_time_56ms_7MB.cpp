#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void dijkstra(int src, vector<vector<int>>& D,
              long long B, long long C, vector<long long>& dist){
    const int N = dist.size();

    fill(dist.begin(), dist.end(), INF);

    set<pair<long long, int>> statesSet;
    dist[src] = 0;
    statesSet.insert({dist[src], src});

    while(!statesSet.empty()){
        int node = statesSet.begin()->second;
        statesSet.erase(statesSet.begin());

        for(int nextNode = 0; nextNode < N; ++nextNode){
            long long nextDist = dist[node] + D[node][nextNode] * B + C;
            if(nextDist < dist[nextNode]){
                statesSet.erase({dist[nextNode], nextNode});
                dist[nextNode] = nextDist;
                statesSet.insert({dist[nextNode], nextNode});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, A, B, C;
    cin >> N >> A >> B >> C;

    vector<vector<int>> D(N, vector<int>(N));
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> D[i][j];
        }
    }

    // car
    vector<long long> carDist(N);
    dijkstra(0, D, A, 0, carDist);

    // train
    vector<long long> trainDist(N);
    dijkstra(N - 1, D, B, C, trainDist);

    // res
    long long res = carDist[N - 1];
    for(int i = 0; i < N; ++i){
        res = min(res, carDist[i] + trainDist[i]);
    }

    cout << res;

    return 0;
}