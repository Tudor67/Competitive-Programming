#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    using P2 = pair<long long, int>;
    priority_queue<P2, vector<P2>, greater<P2>> busy;
    priority_queue<int, vector<int>, greater<int>> active;

    for(int i = 0; i < N; ++i){
        active.push(i);
    }

    vector<long long> res(N);
    for(int i = 0; i < M; ++i){
        long long T, W, S;
        cin >> T >> W >> S;

        while(!busy.empty() && busy.top().first <= T){
            active.push(busy.top().second);
            busy.pop();
        }

        if(!active.empty()){
            int person = active.top();
            active.pop();

            res[person] += W;

            busy.push({T + S, person});
        }
    }

    for(long long r: res){
        cout << r << "\n";
    }

    return 0;
}