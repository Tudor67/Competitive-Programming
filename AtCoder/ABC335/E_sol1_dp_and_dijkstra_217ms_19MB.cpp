#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }

    vector<vector<int>> G(N);
    for(int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    // dp[currNode]: max score from 1st node to currNode
    vector<int> dp(N);
    dp[0] = 1;

    set<pair<int, int>> statesSet;
    statesSet.insert({A[0], 0});

    while(!statesSet.empty()){
        int node = statesSet.begin()->second;
        statesSet.erase(statesSet.begin());

        for(int nextNode: G[node]){
            if(A[node] <= A[nextNode]){
                int newDP = dp[node] + (int)(A[node] != A[nextNode]);
                if(newDP > dp[nextNode]){
                    statesSet.erase({A[nextNode], nextNode});
                    dp[nextNode] = newDP;
                    statesSet.insert({A[nextNode], nextNode});
                }
            }
        }
    }

    cout << dp[N - 1];

    return 0;
}