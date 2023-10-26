#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> L(N);
    vector<long long> R(N);
    for(int i = 0; i < N; ++i){
        long long T, D;
        cin >> T >> D;
        L[i] = T;
        R[i] = T + D;
    }

    auto incStartHeapComp = [&](int lhs, int rhs){
        return (L[lhs] > L[rhs]);
    };

    auto incEndHeapComp = [&](int lhs, int rhs){
        return (R[lhs] > R[rhs]);
    };

    priority_queue<int, vector<int>, decltype(incStartHeapComp)> laterCandidates(incStartHeapComp);
    priority_queue<int, vector<int>, decltype(incEndHeapComp)> currentCandidates(incEndHeapComp);
    for(int i = 0; i < N; ++i){
        laterCandidates.push(i);
    }

    long long res = 0;
    long long currentTime = 0;
    while(!laterCandidates.empty() || !currentCandidates.empty()){
        if(currentCandidates.empty()){
            currentTime = max(currentTime, L[laterCandidates.top()]);
        }
        while(!laterCandidates.empty() && L[laterCandidates.top()] <= currentTime){
            int i = laterCandidates.top();
            laterCandidates.pop();
            currentCandidates.push(i);
        }
        while(!currentCandidates.empty() && R[currentCandidates.top()] < currentTime){
            currentCandidates.pop();
        }
        if(!currentCandidates.empty()){
            res += 1;
            currentTime = max(currentTime, L[currentCandidates.top()]) + 1;
            currentCandidates.pop();
        }
    }

    cout << res;

    return 0;
}