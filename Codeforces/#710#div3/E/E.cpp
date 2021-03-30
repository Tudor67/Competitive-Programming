#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int N;
    cin >> N;

    vector<int> q(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> q[i];
    }

    vector<int> minP(N + 1);
    vector<int> maxP(N + 1);

    for(int i = 1; i <= N; ++i){
        if(q[i - 1] != q[i]){
            minP[i] = q[i];
            maxP[i] = q[i];
        }
    }

    vector<bool> vis(N + 1, false);
    for(int i = 1; i <= N; ++i){
        vis[q[i]] = true;
    }

    set<int> freeElems;
    for(int elem = 1; elem <= N; ++elem){
        if(!vis[elem]){
            freeElems.insert(elem);
        }
    }

    set<int> freeElemsCopy = freeElems;
    for(int i = 1; i <= N; ++i){
        if(minP[i] == 0){
            auto it = freeElems.begin();
            minP[i] = *it;
            freeElems.erase(it);
        }
    }

    freeElems = freeElemsCopy;
    for(int i = 1; i <= N; ++i){
        if(maxP[i] == 0){
            auto it = prev(freeElems.lower_bound(q[i]));
            maxP[i] = *it;
            freeElems.erase(it);
        }
    }

    for(int i = 1; i <= N; ++i){
        cout << minP[i] << " ";
    }
    cout << "\n";

    for(int i = 1; i <= N; ++i){
        cout << maxP[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tests;
    cin >> tests;

    while(tests > 0){
        solve(cin, cout);
        tests -= 1;
    }

    return 0;
}