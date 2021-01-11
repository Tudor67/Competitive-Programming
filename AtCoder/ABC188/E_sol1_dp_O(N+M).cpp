#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    vector<vector<int>> g(n + 1);
    int x, y;
    for(int i = 1; i <= m; ++i){
        cin >> x >> y;
        g[x].push_back(y);
    }

    int answer = INT_MIN;
    vector<int> maxFrom(n + 1, 0);
    for(int node = n; node >= 1; --node){
        int maxChild = INT_MIN;
        for(int child: g[node]){
            maxChild = max(maxFrom[child], maxChild);
        }
        if(maxChild != INT_MIN){
            answer = max(maxChild - a[node], answer);
        }
        maxFrom[node] = max(a[node], maxChild);
    }

    cout << answer;

    return 0;
}