#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> T(N);
    vector<long long> D(N);
    for(int i = 0; i < N; ++i){
        cin >> T[i] >> D[i];
    }

    using P2 = pair<long long, long long>;
    priority_queue<P2, vector<P2>, greater<P2>> laterCandidates;   // (l, r) pairs
    priority_queue<P2, vector<P2>, greater<P2>> currentCandidates; // (r, l) pairs
    for(int i = 0; i < N; ++i){
        long long l = T[i];
        long long r = T[i] + D[i];
        laterCandidates.push({l, r});
    }

    long long res = 0;
    long long currentTime = 0;
    while(!laterCandidates.empty() || !currentCandidates.empty()){
        if(currentCandidates.empty()){
            currentTime = max(currentTime, laterCandidates.top().first);
        }
        while(!laterCandidates.empty() && laterCandidates.top().first <= currentTime){
            long long l = laterCandidates.top().first;
            long long r = laterCandidates.top().second;
            laterCandidates.pop();
            currentCandidates.push({r, l});
        }
        while(!currentCandidates.empty() && currentCandidates.top().first < currentTime){
            currentCandidates.pop();
        }
        if(!currentCandidates.empty()){
            res += 1;
            currentTime = max(currentTime, currentCandidates.top().second) + 1;
            currentCandidates.pop();
        }
    }

    cout << res;

    return 0;
}