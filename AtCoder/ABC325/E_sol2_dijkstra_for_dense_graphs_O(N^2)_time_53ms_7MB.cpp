#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void dijkstra(int src, vector<vector<int>>& D,
              long long B, long long C, vector<long long>& dist){
    const int N = dist.size();

    fill(dist.begin(), dist.end(), INF);
    dist[src] = 0;

    vector<bool> processed(N, false);

    for(int iteration = 1; iteration <= N - 1; ++iteration){
        long long minDist = INF;
        int minDistIndex = 0;
        for(int i = 0; i < N; ++i){
            if(!processed[i] && dist[i] < minDist){
                minDist = dist[i];
                minDistIndex = i;
            }
        }

        processed[minDistIndex] = true;

        for(int j = 0; j < N; ++j){
            dist[j] = min(dist[j], dist[minDistIndex] + D[minDistIndex][j] * B + C);
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